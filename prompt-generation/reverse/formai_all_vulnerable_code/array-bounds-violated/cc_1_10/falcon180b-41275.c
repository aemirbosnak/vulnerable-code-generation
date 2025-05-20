//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define PORT 110
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char username[50], password[50], command[MAXLINE];
    char response[MAXLINE];
    int n;
    char *ptr;
    int i;

    if (argc!= 4) {
        printf("Usage: %s <username> <password> <command>\n", argv[0]);
        return 1;
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);
    strcpy(command, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        return 1;
    }

    printf("Connecting to POP3 server...\n");
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "localhost", &serveraddr.sin_addr.s_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("Error: Failed to connect to POP3 server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to POP3 server\n");

    if (send(sockfd, username, strlen(username), 0) < 0) {
        printf("Error: Failed to send username\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, password, strlen(password), 0) < 0) {
        printf("Error: Failed to send password\n");
        close(sockfd);
        return 1;
    }

    if (send(sockfd, command, strlen(command), 0) < 0) {
        printf("Error: Failed to send command\n");
        close(sockfd);
        return 1;
    }

    while ((n = recv(sockfd, response, MAXLINE, 0)) > 0) {
        response[n] = '\0';
        printf("%s\n", response);
    }

    close(sockfd);
    return 0;
}