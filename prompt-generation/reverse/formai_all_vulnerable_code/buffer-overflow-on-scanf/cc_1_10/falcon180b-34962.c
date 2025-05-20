//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    char hostname[256];
    char username[256];
    char password[256];
    char command[BUF_SIZE];
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, command, BUF_SIZE, 0);

    if (strcmp(command, "+OK")!= 0) {
        printf("Error authenticating\n");
        exit(1);
    }

    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, command, BUF_SIZE, 0);

    if (strcmp(command, "+OK")!= 0) {
        printf("Error authenticating\n");
        exit(1);
    }

    printf("Authenticated\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, BUF_SIZE, stdin);

        if (strcmp(command, "quit\n") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);
        send(sockfd, "\r\n", 2, 0);

        recv(sockfd, command, BUF_SIZE, 0);
        printf("%s", command);
    }

    close(sockfd);
    exit(0);
}