//Code Llama-13B DATASET v1.0 Category: Sorting ; Style: distributed
/* Distributed Sorting Example Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER_SIZE 1024

struct client_info {
    int socket;
    struct sockaddr_in address;
};

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_data(int socket, void *data, size_t size) {
    ssize_t bytes_sent = send(socket, data, size, 0);
    if (bytes_sent < 0) {
        error("Error sending data");
    }
}

void receive_data(int socket, void *data, size_t size) {
    ssize_t bytes_received = recv(socket, data, size, 0);
    if (bytes_received < 0) {
        error("Error receiving data");
    }
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_len = sizeof(struct sockaddr_in);
    char buffer[MAX_BUFFER_SIZE];
    int num_clients = 0;
    struct client_info clients[MAX_CLIENTS];

    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Error binding socket");
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        error("Error listening on socket");
    }

    // Accept incoming connections
    while (1) {
        printf("Waiting for incoming connection...\n");
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_len);
        if (client_socket < 0) {
            error("Error accepting connection");
        }

        // Add the client to the list of clients
        clients[num_clients].socket = client_socket;
        clients[num_clients].address = client_address;
        num_clients++;

        // Send a welcome message to the client
        sprintf(buffer, "Welcome to the server!\n");
        send_data(client_socket, buffer, strlen(buffer));

        // Receive data from the client
        receive_data(client_socket, buffer, MAX_BUFFER_SIZE);
        printf("Received data from client: %s\n", buffer);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}