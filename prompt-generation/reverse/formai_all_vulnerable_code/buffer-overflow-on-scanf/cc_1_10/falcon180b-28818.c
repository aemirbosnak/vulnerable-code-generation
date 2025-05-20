//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char host[64];
    char user[64];
    char pass[64];
    int port = 110;
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[BUF_SIZE];
    char command[BUF_SIZE];

    printf("Enter POP3 host: ");
    scanf("%s", host);
    printf("Enter username: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", pass);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s\n", host);

    sprintf(command, "USER %s", user);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, buffer, BUF_SIZE, 0);
    printf("Server response: %s\n", buffer);

    sprintf(command, "PASS %s", pass);
    send(sockfd, command, strlen(command), 0);

    recv(sockfd, buffer, BUF_SIZE, 0);
    printf("Server response: %s\n", buffer);

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        memset(command, 0, BUF_SIZE);

        printf("Enter command (QUIT to exit): ");
        scanf("%s", command);

        if (strcmp(command, "QUIT") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);

        recv(sockfd, buffer, BUF_SIZE, 0);
        printf("Server response: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}