//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void *handle_client(void *client_socket);
void forward_request(int client_socket, char *request);
void send_response(int client_socket, int server_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create a socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

    while (1) {
        // Accept a client connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_client, (void *)(intptr_t)client_socket) != 0) {
            perror("Thread creation failed");
            close(client_socket);
        }
        pthread_detach(tid);  // Detach the thread to clean up resources when done
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int sock = (intptr_t)client_socket;
    char buffer[BUFFER_SIZE];

    // Read the client's request
    int read_size = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (read_size < 0) {
        perror("Receive failed");
        close(sock);
        return NULL;
    }
    
    buffer[read_size] = '\0'; // Null-terminate the received string
    printf("Received request:\n%s\n", buffer);

    forward_request(sock, buffer);
    close(sock);
    return NULL;
}

void forward_request(int client_socket, char *request) {
    int server_socket;
    struct sockaddr_in server_addr;
    char host[100], path[200];
    
    sscanf(request, "GET http://%99[^/]/%199s", host, path);

    // Create a socket to the target server
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation for server failed");
        return;
    }

    // Resolve server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);  // HTTP port
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use relevant server IP here

    // Establish a connection to the server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect to server failed");
        close(server_socket);
        return;
    }

    // Send the request to the server
    send(server_socket, request, strlen(request), 0);
    // Send back server's response to the client
    send_response(client_socket, server_socket);

    close(server_socket);
}

void send_response(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive the response from the server and forward it to the client
    while ((bytes_received = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';
        send(client_socket, buffer, bytes_received, 0);
    }
}