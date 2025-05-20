//FormAI DATASET v1.0 Category: Socket programming ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

// Define a struct to hold client information
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_t;

// Define a struct to pass arguments to pthread_create
typedef struct {
    int client_fd;
    client_t *clients;
    int *num_clients;
} thread_args_t;

// Define a function to handle incoming client connections
void *handle_connection(void *args_ptr) {
    // Cast arguments to correct types
    thread_args_t *args = (thread_args_t *) args_ptr;
    int client_fd = args->client_fd;
    client_t *clients = args->clients;
    int *num_clients = args->num_clients;

    // Store client information in clients array
    client_t new_client = {client_fd};
    socklen_t client_addr_len = sizeof(new_client.address);
    getpeername(client_fd, (struct sockaddr *) &new_client.address, &client_addr_len);
    clients[*num_clients] = new_client;
    (*num_clients)++;

    // Receive and broadcast messages from client
    char buffer[BUFFER_SIZE];
    int recv_size;
    while ((recv_size = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        // Add null terminator to received message
        buffer[recv_size] = '\0';

        // Broadcast message to all connected clients
        for (int i = 0; i < *num_clients; i++) {
            if (clients[i].socket_fd != client_fd) {
                send(clients[i].socket_fd, buffer, strlen(buffer), 0);
            }
        }
    }

    // Remove client from clients array
    for (int i = 0; i < *num_clients; i++) {
        if (clients[i].socket_fd == client_fd) {
            for (int j = i+1; j < *num_clients; j++) {
                clients[j-1] = clients[j];
            }
            (*num_clients)--;
            break;
        }
    }

    // Close client socket and exit thread
    close(client_fd);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);
    client_t clients[MAX_CLIENTS];
    int num_clients = 0;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options to allow reuse of address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server socket to address and port
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming client connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Accept client connections and start threads to handle them
    pthread_t threads[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if ((client_fd = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &addrlen)) < 0) {
            perror("accept failed");
            continue;
        }
        thread_args_t args = {client_fd, clients, &num_clients};
        if (pthread_create(&threads[i], NULL, handle_connection, (void *) &args)) {
            perror("pthread_create failed");
            continue;
        }
    }

    // Wait for threads to finish
    for (int i = 0; i < MAX_CLIENTS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close server socket and exit program
    close(server_fd);
    return 0;
}