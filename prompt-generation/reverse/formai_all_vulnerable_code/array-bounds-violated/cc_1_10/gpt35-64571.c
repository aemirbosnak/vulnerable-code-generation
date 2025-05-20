//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CONNECTIONS 10

// Declare global variables
int sock_fd;
struct sockaddr_in server_addr;
int server_port = 8080;
char* server_ip = "127.0.0.1";
pthread_t threads[MAX_CONNECTIONS];
int thread_count = 0;

// Declare thread function
void* handle_connection(void* arg) {
    int client_sock = *((int*) arg);
    char buffer[1024];
    int read_size;

    // Read client message
    read_size = recv(client_sock, buffer, 1024, 0);
    buffer[read_size] = '\0';

    // Print client message
    printf("Client message: %s\n", buffer);

    // Send response to client
    char* response = "Message received!";
    send(client_sock, response, strlen(response), 0);

    // Close connection
    close(client_sock);
    thread_count--;

    return NULL;
}

int main(int argc, char** argv) {

    // Create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address information
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Bind socket to server address
    if (bind(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(1);
    }

    // Listen for clients
    if (listen(sock_fd, MAX_CONNECTIONS) < 0) {
        perror("Listen failed");
        exit(1);
    }

    printf("Server started and listening on %s:%d\n", server_ip, server_port);

    // Handle clients in a loop
    while(1) {
        struct sockaddr_in client_addr;
        int addrlen = sizeof(client_addr);

        // Accept client connection
        int client_sock = accept(sock_fd, (struct sockaddr*) &client_addr, (socklen_t*) &addrlen);

        // Create new thread to handle client
        if (thread_count < MAX_CONNECTIONS) {
            pthread_create(&threads[thread_count], NULL, handle_connection, &client_sock);
            thread_count++;
        } else {
            // Too many clients, reject connection
            char* response = "Server is busy. Please try again later.";
            send(client_sock, response, strlen(response), 0);
            close(client_sock);
        }
    }

    return 0;
}