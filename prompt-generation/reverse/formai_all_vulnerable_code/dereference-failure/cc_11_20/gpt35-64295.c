//FormAI DATASET v1.0 Category: Chat server ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 256

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s [PORT]\n", argv[0]);
        exit(1);
    }

    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;
    int address_length = sizeof(server_address);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Socket option set failed");
        exit(1);
    }

    // Prepare server address structure
    memset(&server_address, 0, address_length);
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Socket bind failed");
        exit(1);
    }

    // Listen for clients
    if (listen(server_fd, 1) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server listening on port %s\n", argv[1]);

    while(1) {
        // Accept incoming client connection
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t*)&address_length)) < 0) {
            perror("Accept failed");
            exit(1);
        }

        printf("Client connected\n");

        int message_length;
        char *welcome_message = "Welcome to the chat server!\n";

        // Send welcome message to client
        if((message_length = send(client_fd, welcome_message, strlen(welcome_message), 0)) < 0) {
            perror("Send failed");
            exit(1);
        }

        // Start chat loop
        while(1) {
            // Receive message from client
            if((message_length = recv(client_fd, buffer, BUFFER_SIZE, 0)) < 0) {
                perror("Receive failed");
                exit(1);
            } else if(message_length == 0) {
                // Client disconnected
                printf("Client disconnected\n");
                break;
            } else {
                // Print message
                printf("Client: %s", buffer);

                // Echo message back to client
                if(send(client_fd, buffer, message_length, 0) < 0) {
                    perror("Send failed");
                    exit(1);
                }
            }

            // Clear buffer
            memset(buffer, 0, BUFFER_SIZE);
        }

        // Close client connection
        close(client_fd);
    }

    // Close server socket
    close(server_fd);

    return 0;
}