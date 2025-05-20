//FormAI DATASET v1.0 Category: Client Server Application ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_error(const char *error_message){
    perror(error_message);
    exit(EXIT_FAILURE);
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, address_length, bytes_received, i;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];

    // Create the server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Could not create socket");
    }

    // Set socket options
    int yes = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
        handle_error("Socket options failure");
    }

    // Bind server socket to port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        handle_error("Could not bind socket to port");
    }

    // Listen for connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        handle_error("Could not listen for connections");
    }

    printf("Medieval chat server running on port 8888\n");

    // Main chat loop
    while (1) {
        // Accept new client connections
        address_length = sizeof(struct sockaddr_in);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, (socklen_t *) &address_length);

        // Receive and send messages to all connected clients
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';

            // Prepare response
            snprintf(response, BUFFER_SIZE, "[%s:%d] says: %s", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);

            // Send response to all connected clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (i != server_socket) {
                    if (send(i, response, strlen(response), 0) == -1) {
                        handle_error("Failed to send message to client");
                    }
                }
            }
        }

        // Client disconnected
        printf("[%s:%d] disconnected\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        close(client_socket);
    }

    return 0;
}