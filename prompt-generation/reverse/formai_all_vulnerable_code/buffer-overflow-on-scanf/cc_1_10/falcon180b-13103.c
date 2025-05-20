//Falcon-180B DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    char *token;
    char *username = "username";
    char *password = "password";

    printf("Welcome to the Futuristic Email Client!\n");
    printf("Enter your email address: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    portno = 8080;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("localhost");
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, 1024, stdin);
        token = strtok(buffer, " ");
        if (strcmp(token, "login") == 0) {
            send(sockfd, username, strlen(username), 0);
            send(sockfd, password, strlen(password), 0);
            printf("Logged in successfully\n");
        } else if (strcmp(token, "exit") == 0) {
            close(sockfd);
            exit(0);
        } else if (strcmp(token, "send") == 0) {
            token = strtok(NULL, " ");
            send(sockfd, token, strlen(token), 0);
        } else if (strcmp(token, "read") == 0) {
            send(sockfd, "read", strlen("read"), 0);
            while ((n = recv(sockfd, buffer, 1024, 0)) > 0) {
                printf("%s", buffer);
            }
        }
    }

    return 0;
}