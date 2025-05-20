//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define POP3_PORT 110

int main() {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char username[50];
    char password[50];
    char command[100];
    char response[100];

    printf("Enter POP3 server IP address: ");
    scanf("%s", &serveraddr.sin_addr.s_addr);
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(POP3_PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Enter POP3 username: ");
    scanf("%s", username);
    printf("Enter POP3 password: ");
    scanf("%s", password);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    memset(buffer, 0, BUFFER_SIZE);
    sprintf(command, "STAT\r\n");
    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);
    return 0;
}