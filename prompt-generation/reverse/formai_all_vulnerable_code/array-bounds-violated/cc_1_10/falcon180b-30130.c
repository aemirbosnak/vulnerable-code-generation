//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUFFER_SIZE 1024

void main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[20], password[20], command[50];
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(0);
    }

    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, "192.168.1.100", &serveraddr.sin_addr);
    serveraddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error in connecting to server\n");
        exit(0);
    }

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (n <= 0) {
            printf("Connection closed\n");
            break;
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
}