//FormAI DATASET v1.0 Category: Networking ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    srand(time(NULL));

    // Create socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to address and port
    struct sockaddr_in address = {0};
    address.sin_family = AF_INET;
    address.sin_port = htons(PORT);
    address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        // Accept incoming connection
        int address_length = sizeof(address);
        int client_fd = accept(server_fd, (struct sockaddr*)&address, (socklen_t*)&address_length);
        if (client_fd == -1) {
            perror("Accept failed");
            continue;
        }

        printf("New client connection from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        // Generate random initial color for client
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;

        // Send client the initial color
        char buffer[BUFFER_SIZE] = {0};
        sprintf(buffer, "COLOR %d %d %d\n", r, g, b);
        send(client_fd, buffer, strlen(buffer), 0);

        // Wait for client messages
        while (1) {
            // Receive message
            int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1) {
                perror("Receive failed");
                close(client_fd);
                break;
            } else if (bytes_received == 0) {
                printf("Connection closed by %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                close(client_fd);
                break;
            }

            // Parse message
            buffer[bytes_received] = '\0';
            char* command = strtok(buffer, " ");
            if (strcmp(command, "COLOR") == 0) {
                // Change client color
                r = atoi(strtok(NULL, " "));
                g = atoi(strtok(NULL, " "));
                b = atoi(strtok(NULL, " "));
                printf("Client %s:%d changed color to (%d, %d, %d)\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), r, g, b);
            } else {
                printf("Unknown command from %s:%d: %s\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), command);
            }
        }
    }

    return 0;
}