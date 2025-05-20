//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to print error message and exit
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to handle each client connection
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);

        // Send the message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (i!= client_socket) {
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }

    close(client_socket);
    printf("Client %d disconnected\n", client_socket);
}

int main() {
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error("socket failed");
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error("setsockopt");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("bind failed");
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        error("listen");
    }

    printf("Server started on port 8080\n");

    while (1) {
        // Accept incoming connections
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            error("accept");
        }

        // Handle each client connection in a separate thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, (void *)handle_client, (void *)client_socket)!= 0) {
            error("pthread_create");
        }
    }

    return 0;
}