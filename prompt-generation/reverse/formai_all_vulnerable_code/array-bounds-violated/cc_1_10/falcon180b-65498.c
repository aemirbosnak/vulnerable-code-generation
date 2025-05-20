//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100

// Function to print error message and exit
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to receive data from client
void receive_data(int client_socket) {
    char buffer[MAX];
    int bytes_received = 0;
    while ((bytes_received = recv(client_socket, buffer, MAX, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client: %s\n", buffer);
    }
    if (bytes_received == 0) {
        printf("Client disconnected.\n");
    } else {
        error("recv() failed");
    }
}

// Function to send data to client
void send_data(int client_socket) {
    char buffer[MAX];
    printf("Enter message to send: ");
    fgets(buffer, MAX, stdin);
    send(client_socket, buffer, strlen(buffer), 0);
}

// Main function
int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket() failed");
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind server address to socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind() failed");
    }

    // Listen for client connections
    if (listen(server_socket, 5) < 0) {
        error("listen() failed");
    }

    printf("Server listening on port 8080...\n");

    // Accept client connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
        error("accept() failed");
    }

    printf("Client connected.\n");

    // Receive data from client
    receive_data(client_socket);

    // Send data to client
    send_data(client_socket);

    // Close sockets
    close(server_socket);
    close(client_socket);

    return 0;
}