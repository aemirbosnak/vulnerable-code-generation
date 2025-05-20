//Falcon-180B DATASET v1.0 Category: Email Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1000

typedef struct {
    char username[50];
    char password[50];
    char email[100];
    char message[MAX_SIZE];
} User;

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[MAX_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    User user;

    printf("Enter your username: ");
    scanf("%s", user.username);

    printf("Enter your password: ");
    scanf("%s", user.password);

    printf("Enter your email: ");
    scanf("%s", user.email);

    portno = 8080;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error binding to port\n");
        exit(0);
    }

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    if (newsockfd < 0) {
        printf("Error accepting connection\n");
        exit(0);
    }

    printf("Connection established with client\n");

    while (1) {
        bzero(buffer, MAX_SIZE);
        n = read(newsockfd, buffer, MAX_SIZE);

        if (n < 0) {
            printf("Error reading from client\n");
            exit(0);
        }

        buffer[n] = '\0';

        printf("Received message: %s\n", buffer);

        strcpy(user.message, buffer);

        send(newsockfd, user.message, strlen(user.message), 0);
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}