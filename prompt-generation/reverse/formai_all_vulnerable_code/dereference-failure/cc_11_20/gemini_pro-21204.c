//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 1024

typedef struct {
    int sockfd;
    char username[32];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

int main() {
    int listenfd, connfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(5000);

    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(listenfd, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        cli_len = sizeof(cli_addr);
        connfd = accept(listenfd, (struct sockaddr *) &cli_addr, &cli_len);
        if (connfd < 0) {
            perror("accept");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            close(connfd);
            continue;
        }

        char buf[MAX_MSG_LEN];
        recv(connfd, buf, MAX_MSG_LEN, 0);

        char *username = strtok(buf, ":");
        char *message = strtok(NULL, ":");

        if (strlen(username) >= 32) {
            close(connfd);
            continue;
        }

        strcpy(clients[num_clients].username, username);
        clients[num_clients].sockfd = connfd;
        num_clients++;

        printf("%s has joined the chat\n", username);

        char welcome_msg[MAX_MSG_LEN];
        sprintf(welcome_msg, "Welcome to the chat, %s!\n", username);
        send(connfd, welcome_msg, strlen(welcome_msg), 0);

        while (1) {
            recv(connfd, buf, MAX_MSG_LEN, 0);

            if (strcmp(buf, "/exit") == 0) {
                close(connfd);
                num_clients--;
                printf("%s has left the chat\n", username);
                break;
            }

            char msg[MAX_MSG_LEN];
            sprintf(msg, "%s: %s\n", username, buf);

            for (int i = 0; i < num_clients; i++) {
                if (clients[i].sockfd != connfd) {
                    send(clients[i].sockfd, msg, strlen(msg), 0);
                }
            }
        }
    }

    close(listenfd);
    return 0;
}