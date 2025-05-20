//Falcon-180B DATASET v1.0 Category: Website Uptime Monitor ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_LENGTH 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    char buffer[MAX_REQUEST_LENGTH];
    memset(buffer, 0, MAX_REQUEST_LENGTH);
    int bytes_received = 0;

    while ((bytes_received = recv(clients[num_clients], buffer, MAX_REQUEST_LENGTH, 0)) > 0) {
        if (buffer[bytes_received - 1] == '\n') {
            buffer[--bytes_received] = '\0';
        }

        printf("Client %d sent: %s", num_clients, buffer);
    }

    close(clients[num_clients]);
    clients[num_clients] = 0;
    num_clients--;
}

int main() {
    int listen_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for client connection...\n");

        new_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)new_socket);
    }

    return 0;
}