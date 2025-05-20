//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: romantic
// romantic_chat_server.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_BUFFER_SIZE 256

// Struct to represent a client
typedef struct {
    int socket_fd;
    struct sockaddr_in address;
} client_t;

// Function to send a message to all clients
void send_message_to_all_clients(client_t* clients, int num_clients, char* message) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].socket_fd, message, strlen(message), 0);
    }
}

int main(int argc, char* argv[]) {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Set address information
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);
    address.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    bind(server_socket, (struct sockaddr*)&address, sizeof(address));

    // Listen for incoming connections
    listen(server_socket, MAX_CLIENTS);

    // Create an array of clients
    client_t clients[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        // Accept an incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_len);

        // Add the client to the array of clients
        clients[num_clients].socket_fd = client_socket;
        clients[num_clients].address = client_address;
        num_clients++;

        // Receive a message from the client
        char buffer[MAX_BUFFER_SIZE];
        recv(client_socket, buffer, MAX_BUFFER_SIZE, 0);

        // Send the message to all clients
        send_message_to_all_clients(clients, num_clients, buffer);

        // Close the socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}