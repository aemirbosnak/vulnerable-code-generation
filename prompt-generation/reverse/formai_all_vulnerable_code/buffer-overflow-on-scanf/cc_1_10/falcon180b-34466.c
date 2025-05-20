//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>

#define MAX_LINE 1024

int main() {
    int sockfd;
    char hostname[64];
    char username[32];
    char password[32];
    char command[MAX_LINE];
    int port;
    struct sockaddr_in serveraddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_LINE, stdin);

        if (strcasecmp(command, "QUIT") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);

        char response[MAX_LINE];
        memset(response, 0, MAX_LINE);

        int bytes_received = recv(sockfd, response, MAX_LINE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        response[bytes_received-1] = '\0';
        printf("Response: %s\n", response);
    }

    close(sockfd);
    return 0;
}