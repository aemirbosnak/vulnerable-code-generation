//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: calm
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define MAX_BUFFER 1024
#define SERVER_ADDRESS "127.0.0.1"

int main() {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER];
    char command[32];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

    printf("Connected to email server.\n");
    printf("Enter command (type 'quit' to exit):\n");

    while (true) {
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "list") == 0) {
            send(sockfd, command, strlen(command), 0);
            recv(sockfd, buffer, MAX_BUFFER, 0);
            printf("%s\n", buffer);
        } else if (strcmp(command, "get") == 0) {
            char email[32];
            printf("Enter email address: ");
            scanf("%s", email);

            send(sockfd, command, strlen(command), 0);
            send(sockfd, email, strlen(email), 0);

            recv(sockfd, buffer, MAX_BUFFER, 0);
            printf("%s\n", buffer);
        } else if (strcmp(command, "send") == 0) {
            char to[32], subject[32], message[1024];
            printf("Enter recipient's email address: ");
            scanf("%s", to);
            printf("Enter subject: ");
            scanf("%s", subject);
            printf("Enter message: ");
            fgets(message, sizeof(message), stdin);
            message[strlen(message) - 1] = '\0';

            send(sockfd, command, strlen(command), 0);
            send(sockfd, to, strlen(to), 0);
            send(sockfd, subject, strlen(subject), 0);
            send(sockfd, message, strlen(message), 0);

            recv(sockfd, buffer, MAX_BUFFER, 0);
            printf("%s\n", buffer);
        } else if (strcmp(command, "quit") == 0) {
            send(sockfd, command, strlen(command), 0);
            close(sockfd);
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}