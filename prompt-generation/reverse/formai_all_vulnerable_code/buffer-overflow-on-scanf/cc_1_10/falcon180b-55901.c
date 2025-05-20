//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char hostname[100];
    char username[100];
    char password[100];
    char command[100];
    char response[1000];
    int port = 21;
    int n;

    printf("Enter the FTP server hostname: ");
    scanf("%s", hostname);

    printf("Enter the FTP server username: ");
    scanf("%s", username);

    printf("Enter the FTP server password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        printf("Enter FTP command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);

        n = recv(sockfd, response, sizeof(response), 0);

        if (n < 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        response[n] = '\0';

        printf("Server response: %s\n", response);
    }

    close(sockfd);

    return 0;
}