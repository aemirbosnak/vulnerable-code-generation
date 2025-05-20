//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int clients[MAX_CLIENTS][2];
int num_clients;

void *handle_client(void *client_socket) {
    int client_socket_fd = *(int *) client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket_fd, buffer, bytes_received, 0);
    }

    close(client_socket_fd);
    return NULL;
}

int main() {
    int server_socket_fd, new_socket_fd, max_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    pthread_t thread_id;

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(server_socket_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(errno);
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        if ((new_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_addr, &client_addr_size)) == -1) {
            perror("accept");
            exit(errno);
        }

        for (int i = 0; i < num_clients; i++) {
            if (clients[i][0] == -1) {
                clients[i][0] = new_socket_fd;
                clients[i][1] = i;
                num_clients++;
                break;
            }
        }

        pthread_create(&thread_id, NULL, handle_client, &new_socket_fd);
    }

    return 0;
}