//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[20], password[20];
    char response[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    char *ptr;
    int len;
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", inet_ntoa(serveraddr.sin_addr));
    printf("Enter POP3 server port: ");
    scanf("%d", &serveraddr.sin_port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: socket creation failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error: connection failed\n");
        exit(1);
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[len] = '\0';
    printf("Server response: %s\n", response);

    if (strstr(response, "+OK") == NULL) {
        printf("Error: authentication failed\n");
        exit(1);
    }

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    len = recv(sockfd, response, BUFFER_SIZE, 0);
    response[len] = '\0';
    printf("Server response: %s\n", response);

    if (strstr(response, "+OK") == NULL) {
        printf("Error: authentication failed\n");
        exit(1);
    }

    while (1) {
        printf("Enter command (QUIT to exit): ");
        scanf("%s", command);

        if (tolower(command[0]) == 'q') {
            sprintf(command, "QUIT\r\n");
            send(sockfd, command, strlen(command), 0);
            break;
        }

        len = recv(sockfd, response, BUFFER_SIZE, 0);
        response[len] = '\0';
        printf("Server response: %s\n", response);
    }

    close(sockfd);
}