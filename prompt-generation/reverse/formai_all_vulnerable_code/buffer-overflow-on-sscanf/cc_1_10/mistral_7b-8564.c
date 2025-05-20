//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 4444
#define MAX_BUF 1024
#define BUFFER_SIZE 256

typedef struct {
    char name[BUFFER_SIZE];
    char email[BUFFER_SIZE];
    char password[BUFFER_SIZE];
} user;

int main() {
    int sockfd, new_sockfd, portno, clilen;
    char buffer[MAX_BUF];
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(sockfd, 5);

    printf("Listening on port %d...\n", SERVER_PORT);

    clilen = sizeof(cli_addr);

    new_sockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);

    printf("New connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    bzero(buffer, MAX_BUF);

    while (1) {
        int len = recv(new_sockfd, buffer, MAX_BUF, 0);

        if (len <= 0) {
            printf("Connection closed\n");
            break;
        }

        char cmd = buffer[0];
        user user_data;

        switch (cmd) {
            case 'R':
                sscanf(buffer + 1, "%s%s%s", user_data.name, user_data.email, user_data.password);
                send(new_sockfd, "Received user data\n", 17, 0);
                break;

            case 'L':
                send(new_sockfd, "Listing users...\n", 15, 0);
                // List users here
                break;

            case 'S':
                // Send email here
                break;

            case 'E':
                // Delete email here
                break;

            case 'Q':
                printf("User %s disconnected.\n", user_data.name);
                close(new_sockfd);
                exit(0);
        }

        bzero(buffer, MAX_BUF);
    }

    close(sockfd);
    close(new_sockfd);
    return 0;
}