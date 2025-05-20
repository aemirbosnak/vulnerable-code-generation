//FormAI DATASET v1.0 Category: Chat server ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address and port
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind socket to the address and port
    if (bind(server_fd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept incoming connection
        if ((client_fd = accept(server_fd, (struct sockaddr*) &client_address, &client_address_len)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Get client details
        char* client_ip = inet_ntoa(client_address.sin_addr);
        int client_port = ntohs(client_address.sin_port);

        // Send welcome message to client
        char welcome_message[BUFFER_SIZE];
        sprintf(welcome_message, "Welcome to the chat server! Your IP address is %s and port is %d\n", client_ip, client_port);
        send(client_fd, welcome_message, strlen(welcome_message), 0);

        // Receive messages from the client
        while (1) {
            int num_bytes;
            if ((num_bytes = recv(client_fd, buffer, BUFFER_SIZE, 0)) <= 0) {
                break;
            }
            buffer[num_bytes] = '\0';
            printf("Received message from %s:%d: %s", client_ip, client_port, buffer);
            
            // Respond to client
            char response[BUFFER_SIZE];
            sprintf(response, "You said: %s", buffer);
            send(client_fd, response, strlen(response), 0);
        }

        // Close client connection
        close(client_fd);
    }

    return 0;
}