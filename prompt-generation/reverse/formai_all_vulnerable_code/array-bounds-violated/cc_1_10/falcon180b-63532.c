//Falcon-180B DATASET v1.0 Category: Networking ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int clients[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int*)client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", *((int*)client_socket), buffer);
    }

    close(*((int*)client_socket));
    free(client_socket);

    return NULL;
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char *message = "Welcome to the server!";

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(12345);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port 12345\n");

    while (1) {
        memset(&client_addr, 0, sizeof(client_addr));
        addrlen = sizeof(client_addr);

        if ((clients[0] = accept(server_socket, (struct sockaddr*)&client_addr, &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client %d connected\n", clients[0]);

        pthread_create(&threads[0], NULL, handle_client, (void*)&clients[0]);
    }

    return 0;
}