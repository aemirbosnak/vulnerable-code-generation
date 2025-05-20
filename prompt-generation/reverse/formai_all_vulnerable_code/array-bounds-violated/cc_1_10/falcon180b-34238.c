//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", *((int *) client_socket), buffer);

        for (int i = 0; i < num_clients; i++) {
            if (i!= *((int *) client_socket)) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(*((int *) client_socket));
    num_clients--;

    return NULL;
}

int main() {
    int opt = 1;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    int client_socket;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, (socklen_t*) &addrlen);

        if (client_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", 45, 0);
            close(client_socket);
            continue;
        }

        client_sockets[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}