//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5000
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket, accept_status;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    char buffer[BUFFER_SIZE];

    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        perror("Listen failed");
        exit(1);
    }

    // Accept incoming connections
    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket == -1) {
            perror("Accept failed");
            exit(1);
        }

        // Receive the file name from the client
        memset(buffer, 0, sizeof(buffer));
        if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Receive failed");
            exit(1);
        }

        // Open the file for writing
        FILE *file = fopen(buffer, "wb");
        if (file == NULL) {
            perror("File open failed");
            exit(1);
        }

        // Receive the file data from the client
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1) {
                perror("Receive failed");
                exit(1);
            }
            if (bytes_received == 0) {
                break;
            }

            // Write the received data to the file
            if (fwrite(buffer, 1, bytes_received, file) != bytes_received) {
                perror("Write failed");
                exit(1);
            }
        }

        // Close the file
        fclose(file);

        // Close the client socket
        close(client_socket);
    }

    // Close the server socket
    close(server_socket);

    return 0;
}