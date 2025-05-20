//GEMINI-pro DATASET v1.0 Category: Wireless Network Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <poll.h>
#include <signal.h>
#include <netinet/in.h>

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[MAX_BUFFER_SIZE];
    int buffer_len;
} client_t;

static int num_connections = 0;
static client_t* clients[MAX_CONNECTIONS];
static struct pollfd fds[MAX_CONNECTIONS + 1];

static void handle_connection(client_t* client) {
    int nread;
    while ((nread = recv(client->sockfd, client->buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        client->buffer_len += nread;
        if (client->buffer_len >= MAX_BUFFER_SIZE) {
            break;
        }
    }

    if (nread == 0) {
        printf("Connection closed by client\n");
        close(client->sockfd);
        fds[client->sockfd].fd = -1;
        num_connections--;
    } else if (nread < 0) {
        perror("recv");
        close(client->sockfd);
        fds[client->sockfd].fd = -1;
        num_connections--;
    }
}

static void handle_new_connection(int listenfd) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int newsockfd;

    if ((newsockfd = accept(listenfd, (struct sockaddr*)&addr, &addrlen)) < 0) {
        perror("accept");
        return;
    }

    if (num_connections >= MAX_CONNECTIONS) {
        printf("Maximum number of connections reached\n");
        close(newsockfd);
        return;
    }

    client_t* client = malloc(sizeof(client_t));
    client->sockfd = newsockfd;
    client->addr = addr;
    client->buffer_len = 0;
    clients[num_connections++] = client;

    fds[newsockfd].fd = newsockfd;
    fds[newsockfd].events = POLLIN;
}

static void handle_signals(int signum) {
    switch (signum) {
        case SIGINT:
            printf("SIGINT received, exiting\n");
            exit(0);
            break;
        case SIGTERM:
            printf("SIGTERM received, exiting\n");
            exit(0);
            break;
    }
}

int main() {
    int listenfd;
    struct sockaddr_in addr;

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listenfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }

    if (listen(listenfd, 5) < 0) {
        perror("listen");
        return -1;
    }

    fds[listenfd].fd = listenfd;
    fds[listenfd].events = POLLIN;

    signal(SIGINT, handle_signals);
    signal(SIGTERM, handle_signals);

    while (1) {
        int nfds = poll(fds, MAX_CONNECTIONS + 1, -1);
        if (nfds == -1) {
            perror("poll");
            continue;
        }

        if (fds[listenfd].revents & POLLIN) {
            handle_new_connection(listenfd);
        }

        for (int i = 1; i < MAX_CONNECTIONS + 1; i++) {
            if (fds[i].fd == -1) {
                continue;
            }

            if (fds[i].revents & (POLLIN | POLLERR)) {
                handle_connection(clients[i - 1]);
            }
        }
    }

    close(listenfd);

    for (int i = 0; i < num_connections; i++) {
        close(clients[i]->sockfd);
        free(clients[i]);
    }

    return 0;
}