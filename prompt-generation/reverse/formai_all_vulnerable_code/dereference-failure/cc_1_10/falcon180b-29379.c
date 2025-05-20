//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void error(const char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd;
    struct addrinfo hints, *servinfo;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((servinfo = getaddrinfo(server, "21", &hints, NULL)) == NULL) {
        error("getaddrinfo");
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);

    if (sockfd == -1) {
        error("socket");
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        error("connect");
    }

    char *buffer = malloc(BUFFER_SIZE);

    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    if (recv(sockfd, response, BUFFER_SIZE, 0) <= 0) {
        error("recv");
    }

    printf("FTP Server response: %s\n", response);

    close(sockfd);
    free(buffer);

    return 0;
}