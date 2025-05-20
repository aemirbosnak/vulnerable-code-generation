//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10
#define SERVER_PORT 8080

int server_socket;
int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc) {
    int client_socket = *(int *) socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);

    return NULL;
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == ECONNABORTED) {
                continue;
            }

            perror("accept");
            exit(1);
        }

        if (client_count >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }

        client_sockets[client_count++] = client_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *) &opt, sizeof(opt));

    while (1) {
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));

        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = INADDR_ANY;
        server_addr.sin_port = htons(SERVER_PORT);

        if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            perror("bind");
            exit(1);
        }

        if (listen(server_socket, 10) == -1) {
            perror("listen");
            exit(1);
        }

        accept_connections();
    }

    return 0;
}