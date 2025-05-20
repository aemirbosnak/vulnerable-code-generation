//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <ctype.h>

#define PORT 8080
#define MAX_CLIENTS 100
#define MESSAGE_SIZE 1024

struct client_data {
    int sockfd;
    char username[32];
};

struct server_data {
    int sockfd;
    struct client_data clients[MAX_CLIENTS];
    int client_count;
};

static int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    return sockfd;
}

static void bind_socket(int sockfd, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }
}

static void listen_socket(int sockfd) {
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }
}

static int accept_client(int sockfd) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int client_sockfd = accept(sockfd, (struct sockaddr *) &addr, &addrlen);
    if (client_sockfd == -1) {
        perror("accept");
        exit(1);
    }
    return client_sockfd;
}

static void handle_client(struct server_data *server, int client_sockfd) {
    char buffer[MESSAGE_SIZE];
    int n;
    while ((n = read(client_sockfd, buffer, MESSAGE_SIZE)) > 0) {
        buffer[n] = '\0';
        if (strcmp(buffer, "/quit") == 0) {
            break;
        }
        if (isalpha(*buffer)) {
            // Broadcast message to all clients
            for (int i = 0; i < server->client_count; i++) {
                if (server->clients[i].sockfd != client_sockfd) {
                    write(server->clients[i].sockfd, buffer, strlen(buffer));
                }
            }
        } else {
            // Private message
            char *name = strtok(buffer, " ");
            char *message = strtok(NULL, "\0");
            int client_index = -1;
            for (int i = 0; i < server->client_count; i++) {
                if (strcmp(server->clients[i].username, name) == 0) {
                    client_index = i;
                    break;
                }
            }
            if (client_index != -1) {
                write(server->clients[client_index].sockfd, message, strlen(message));
            } else {
                write(client_sockfd, "No such user", strlen("No such user"));
            }
        }
    }
    close(client_sockfd);
}

static void *client_thread(void *arg) {
    struct server_data *server = (struct server_data *) arg;
    int client_sockfd = accept_client(server->sockfd);
    char username[32];
    recv(client_sockfd, username, sizeof(username), 0);
    strcpy(server->clients[server->client_count].username, username);
    server->clients[server->client_count].sockfd = client_sockfd;
    server->client_count++;
    handle_client(server, client_sockfd);
    for (int i = 0; i < server->client_count; i++) {
        if (server->clients[i].sockfd == client_sockfd) {
            server->clients[i] = server->clients[server->client_count - 1];
            server->client_count--;
            break;
        }
    }
    pthread_exit(NULL);
}

int main() {
    struct server_data server;
    server.sockfd = create_socket();
    bind_socket(server.sockfd, PORT);
    listen_socket(server.sockfd);
    pthread_t threads[MAX_CLIENTS];
    int i = 0;
    while (1) {
        pthread_create(&threads[i], NULL, client_thread, &server);
        i++;
        if (i >= MAX_CLIENTS) {
            i = 0;
        }
    }
    close(server.sockfd);
    return 0;
}