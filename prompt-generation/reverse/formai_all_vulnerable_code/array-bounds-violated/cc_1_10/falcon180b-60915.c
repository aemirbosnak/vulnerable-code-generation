//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LENGTH 512
#define MAX_RESPONSE_LENGTH 1024

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[64];
    char password[64];
    char command[MAX_COMMAND_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int n;

    printf("Enter POP3 server address: ");
    scanf("%s", inet_ntoa(serveraddr.sin_addr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(110);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    snprintf(command, MAX_COMMAND_LENGTH, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    snprintf(command, MAX_COMMAND_LENGTH, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(response, 0, MAX_RESPONSE_LENGTH);
        n = recv(sockfd, response, MAX_RESPONSE_LENGTH - 1, 0);

        if (n <= 0) {
            break;
        }

        response[n] = '\0';

        printf("%s", response);

        if (strncmp(response, "+OK", 3) == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}