//FormAI DATASET v1.0 Category: Socket programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int socket_fd;
    struct sockaddr_in client_address;
} Client;

Client clients[MAX_CLIENTS];

int num_clients = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    char buffer[BUFFER_SIZE];
    int socket_fd = *((int *) arg);
    int read_size;

    while ((read_size = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';

        pthread_mutex_lock(&mutex);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].socket_fd != socket_fd) {
                send(clients[i].socket_fd, buffer, strlen(buffer), 0);
            }
        }

        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_lock(&mutex);

    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd == socket_fd) {
            for (int j = i; j < num_clients - 1; j++) {
                clients[j] = clients[j + 1];
            }

            num_clients--;

            break;
        }
    }

    pthread_mutex_unlock(&mutex);

    close(socket_fd);

    return NULL;
}

int main() {
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_address, client_address;
    pthread_t clients_thread[MAX_CLIENTS];

    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");

        return EXIT_FAILURE;
    }

    memset(&server_address, 0, sizeof(server_address));

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);

    if (bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket");

        return EXIT_FAILURE;
    }

    if (listen(server_socket_fd, MAX_CLIENTS) < 0) {
        perror("Error listening for connections");

        return EXIT_FAILURE;
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        client_socket_fd = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_len);

        if (client_socket_fd < 0) {
            perror("Error accepting client connection");

            continue;
        }

        pthread_mutex_lock(&mutex);

        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket_fd);
        } else {
            Client client = {client_socket_fd, client_address};

            clients[num_clients] = client;
            num_clients++;

            pthread_create(&clients_thread[num_clients - 1], NULL, handle_client, (void *) &client_socket_fd);

            printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        }

        pthread_mutex_unlock(&mutex);
    }

    return EXIT_SUCCESS;
}