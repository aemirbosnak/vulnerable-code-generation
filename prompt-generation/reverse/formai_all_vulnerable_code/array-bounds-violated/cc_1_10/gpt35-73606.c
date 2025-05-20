//FormAI DATASET v1.0 Category: Networking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT_NUM 8080
#define BUF_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;

    // Create TCP socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Set server address info
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT_NUM);

    // Bind server socket to address and port
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind to port %d\n", PORT_NUM);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Failed to listen for incoming connections\n");
        exit(EXIT_FAILURE);
    }

    printf("Listening for incoming connections on port %d...\n", PORT_NUM);

    // Loop to accept and handle connections
    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket == -1) {
            printf("Failed to accept incoming connection\n");
            exit(EXIT_FAILURE);
        }

        // Get client IP address
        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, INET_ADDRSTRLEN);

        printf("Client connected from %s\n", client_ip);

        // Receive message from client
        char buf[BUF_SIZE];
        ssize_t num_bytes_received = recv(client_socket, buf, BUF_SIZE - 1, 0);
        if (num_bytes_received < 0) {
            printf("Failed to receive message from client\n");
            exit(EXIT_FAILURE);
        }

        buf[num_bytes_received] = '\0';
        printf("Received message from client: %s\n", buf);

        // Send message back to client
        char message[] = "Hello from server!";
        ssize_t num_bytes_sent = send(client_socket, message, strlen(message), 0);
        if (num_bytes_sent < 0) {
            printf("Failed to send message to client\n");
            exit(EXIT_FAILURE);
        }

        printf("Message sent to client: %s\n", message);

        // Close client socket
        close(client_socket);
        printf("Client disconnected\n");
    }

    // Close server socket
    close(server_socket);

    return 0;
}