//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_buffer(char *buffer, int length) {
    int i;
    for (i = 0; i < length; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char *server = "pop.gmail.com";
    int port = 110;
    char username[50] = "your_email_address";
    char password[50] = "your_password";
    char command[50];
    char buffer[BUFFER_SIZE];
    int length;
    int sockfd;
    struct addrinfo *server_info;
    struct addrinfo hints = {
       .ai_family = AF_UNSPEC,
       .ai_socktype = SOCK_STREAM
    };

    if (argc!= 3) {
        printf("Usage:./pop3_client <username> <password>\n");
        return 1;
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);

    if (getaddrinfo(server, NULL, &hints, &server_info)!= 0) {
        printf("Error: unable to resolve server address.\n");
        return 1;
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        printf("Error: unable to create socket.\n");
        return 1;
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Error: unable to connect to server.\n");
        return 1;
    }

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    length = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (length <= 0) {
        printf("Error: unable to receive response from server.\n");
        return 1;
    }

    print_buffer(buffer, length);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    length = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (length <= 0) {
        printf("Error: unable to receive response from server.\n");
        return 1;
    }

    print_buffer(buffer, length);

    close(sockfd);
    freeaddrinfo(server_info);

    return 0;
}