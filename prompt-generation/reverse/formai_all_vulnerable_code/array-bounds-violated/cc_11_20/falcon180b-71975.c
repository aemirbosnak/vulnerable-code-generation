//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];

    if (argc < 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s\n", argv[1]);

    char *user = argv[2];
    char *pass = argv[3];

    char *msg = "USER ";
    strcat(msg, user);
    strcat(msg, "\r\n");
    send(sockfd, msg, strlen(msg), 0);

    char *response = "";
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Connection closed by server\n");
            exit(1);
        }
        buffer[n] = '\0';
        response = strcat(response, buffer);
        if (response[strlen(response) - 2] == '\r' && response[strlen(response) - 1] == '\n') {
            break;
        }
    }

    char *code = strtok(response, " ");
    if (code == NULL || strcmp(code, "+OK")!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    char *capabilities = strtok(NULL, " ");
    while (capabilities!= NULL) {
        printf("%s\n", capabilities);
        capabilities = strtok(NULL, " ");
    }

    char *list = "LIST\r\n";
    send(sockfd, list, strlen(list), 0);

    bzero(buffer, BUFFER_SIZE);
    while (1) {
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Connection closed by server\n");
            exit(1);
        }
        buffer[n] = '\0';
        response = strcat(response, buffer);
        if (response[strlen(response) - 2] == '\r' && response[strlen(response) - 1] == '\n') {
            break;
        }
    }

    printf("Messages:\n%s", response);

    close(sockfd);
    return 0;
}