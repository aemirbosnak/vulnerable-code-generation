//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

void error_handling(const char* msg);
void print_data(const char* data, int size);

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char* server = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((getaddrinfo(server, "21", &hints, &servinfo))!= 0) {
        error_handling("getaddrinfo");
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        error_handling("socket");
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error_handling("connect");
    }

    char* auth_str = (char*) malloc(strlen(username) + strlen(password) + 3);
    sprintf(auth_str, "%s:%s", username, password);

    if (send(sockfd, auth_str, strlen(auth_str), 0) == -1) {
        error_handling("send");
    }

    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        if (recv(sockfd, buffer, BUF_SIZE, 0) == 0) {
            printf("Connection closed by server.\n");
            break;
        }
        print_data(buffer, strlen(buffer));
    }

    close(sockfd);
    free(auth_str);

    return 0;
}

void error_handling(const char* msg) {
    perror(msg);
    exit(1);
}

void print_data(const char* data, int size) {
    printf("Received data: %s\n", data);
}