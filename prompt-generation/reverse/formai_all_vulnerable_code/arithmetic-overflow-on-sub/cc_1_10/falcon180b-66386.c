//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to send data over the socket
void send_data(int client_socket, char *data, int data_size) {
    int bytes_sent = 0;
    while (bytes_sent < data_size) {
        int result = send(client_socket, data + bytes_sent, data_size - bytes_sent, 0);
        if (result == -1) {
            printf("Error sending data\n");
            exit(1);
        }
        bytes_sent += result;
    }
}

// Function to receive data over the socket
void receive_data(int client_socket, char *buffer, int buffer_size) {
    int bytes_received = 0;
    while (bytes_received < buffer_size) {
        int result = recv(client_socket, buffer + bytes_received, buffer_size - bytes_received, 0);
        if (result == -1) {
            printf("Error receiving data\n");
            exit(1);
        }
        if (result == 0) {
            printf("Connection closed by client\n");
            exit(0);
        }
        bytes_received += result;
    }
}

// Function to handle a single client connection
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    // Receive request from client
    receive_data(client_socket, buffer, BUFFER_SIZE);
    printf("Received request: %s\n", buffer);

    // Send response to client
    send_data(client_socket, "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello World", 38);

    // Close client socket
    close(client_socket);
}

// Main function to start the proxy server
int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port 8080\n");

    while (1) {
        // Accept incoming connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Handle client connection in a separate thread
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&client_socket);
    }

    return 0;
}