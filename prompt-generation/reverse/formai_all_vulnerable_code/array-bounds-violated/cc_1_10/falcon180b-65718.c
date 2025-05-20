//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAXLINE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char username[20];
    char password[20];
    char buffer[MAXLINE];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Error: socket() failed\n");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        printf("Error: inet_pton() failed\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: connect() failed\n");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    char auth_str[50];
    sprintf(auth_str, "AUTH LOGIN %s %s", username, password);

    send(sockfd, auth_str, strlen(auth_str), 0);

    char response[MAXLINE];
    int n = recv(sockfd, response, MAXLINE, 0);

    if (n <= 0) {
        printf("Error: recv() failed\n");
        exit(1);
    }

    response[n] = '\0';

    if (strncmp(response, "+OK", 3)!= 0) {
        printf("Error: authentication failed\n");
        exit(1);
    }

    printf("Authentication successful\n");

    char command[50];
    sprintf(command, "STAT");

    send(sockfd, command, strlen(command), 0);

    n = recv(sockfd, response, MAXLINE, 0);

    if (n <= 0) {
        printf("Error: recv() failed\n");
        exit(1);
    }

    response[n] = '\0';

    printf("Server response: %s\n", response);

    close(sockfd);

    return 0;
}