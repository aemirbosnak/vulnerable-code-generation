//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS][2];
int num_clients = 0;
int main_socket;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", *((int *) client_socket) - 3, buffer);
        send(main_socket, buffer, strlen(buffer), 0);
    }

    close(*((int *) client_socket));
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    main_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (main_socket == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(main_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(main_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(main_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        socklen_t client_size;
        printf("Waiting for connections...\n");
        client_size = sizeof(client_addr);
        new_socket = accept(main_socket, (struct sockaddr *)&client_addr, &client_size);

        if (new_socket < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        clients[num_clients][0] = new_socket;
        clients[num_clients][1] = num_clients + 3;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&clients[num_clients - 1]);
    }

    return 0;
}