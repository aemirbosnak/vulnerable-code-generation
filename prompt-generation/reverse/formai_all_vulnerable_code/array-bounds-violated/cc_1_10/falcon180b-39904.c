//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket = -1;
int client_socket[MAX_CLIENTS] = {-1};
int num_clients = 0;

char *message = "Welcome to the server!\n";

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", *((int *) client_socket), buffer);

        send(*((int *) client_socket), message, strlen(message), 0);
    }

    close(*((int *) client_socket));
    free(client_socket);
}

int main() {
    int server_port = 8080;
    struct sockaddr_in server_addr;
    int opt = 1;
    int client_addr_size;
    char *client_addr_str;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr))) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", server_port);

    while (1) {
        client_addr_size = sizeof(struct sockaddr_in);
        client_socket[num_clients] = accept(server_socket, (struct sockaddr *) &server_addr, &client_addr_size);

        if (client_socket[num_clients] == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        client_addr_str = inet_ntoa(server_addr.sin_addr);
        printf("Client %d connected: %s:%d\n", num_clients, client_addr_str, ntohs(server_addr.sin_port));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket[num_clients]);

        num_clients++;
    }

    return 0;
}