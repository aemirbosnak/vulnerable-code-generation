//FormAI DATASET v1.0 Category: Socket programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_PENDING 5
#define MAX_LINE 1024

int main() {

    int server_fd, client_fd;
    struct sockaddr_in server, client;
    socklen_t client_size;
    char buffer[MAX_LINE] = {0};
    int opt = 1;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Prepare address information of server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket to the given address
    if (bind(server_fd, (struct sockaddr *)&server, sizeof(server)) < 0)  {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_PENDING) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port: %d\n", PORT);

    while (1) {
        // Accept incoming connection
        client_size = sizeof(client);
        if ((client_fd = accept(server_fd, (struct sockaddr *)&client, &client_size)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }
        
        printf("Client connected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Set timeout for receiving data
        struct timeval timeout;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        if (setsockopt(client_fd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
            perror("Setsockopt failed");
            exit(EXIT_FAILURE);
        }

        int bytes_received = 0;
        while ((bytes_received = recv(client_fd, buffer, MAX_LINE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Message from client: %s\n", buffer);
            send(client_fd, buffer, strlen(buffer), 0);
            memset(buffer, 0, MAX_LINE);
        }

        if (bytes_received == 0) {
            printf("Client disconnected: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        } else if (bytes_received == -1) {
            printf("Timeout occurred while receiving data from client: %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        }

        // Close connection
        close(client_fd);
    }

    return 0;
}