//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

typedef struct client {
    int sockfd;
    struct sockaddr_in addr;
    char name[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

int main(int argc, char** argv) {
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    struct sockaddr_in serv_addr, cli_addr;
    int n;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        return 1;
    }

    listen(sockfd, MAX_CLIENTS);

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Error on accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(newsockfd);
            continue;
        }

        clients[num_clients].sockfd = newsockfd;
        clients[num_clients].addr = cli_addr;
        clients[num_clients].name[0] = '\0';
        num_clients++;

        printf("New client connected: %s\n", inet_ntoa(cli_addr.sin_addr));

        char buffer[MAX_MSG_SIZE];
        n = recv(newsockfd, buffer, MAX_MSG_SIZE, 0);
        if (n < 0) {
            perror("Error receiving data");
            close(newsockfd);
            continue;
        }

        buffer[n] = '\0';
        if (strcmp(buffer, "JOIN") == 0) {
            n = recv(newsockfd, buffer, MAX_MSG_SIZE, 0);
            if (n < 0) {
                perror("Error receiving data");
                close(newsockfd);
                continue;
            }

            buffer[n] = '\0';
            strncpy(clients[num_clients].name, buffer, sizeof(clients[num_clients].name));
            printf("Client joined: %s\n", clients[num_clients].name);

            strcpy(buffer, "JOINED");
            n = send(newsockfd, buffer, strlen(buffer), 0);
            if (n < 0) {
                perror("Error sending data");
                close(newsockfd);
                continue;
            }
        } else {
            printf("Unknown command: %s\n", buffer);
            strcpy(buffer, "ERROR");
            n = send(newsockfd, buffer, strlen(buffer), 0);
            if (n < 0) {
                perror("Error sending data");
                close(newsockfd);
                continue;
            }
        }
    }

    return 0;
}