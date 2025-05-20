//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void mystic_echo(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the string
        printf("Echoing: %s", buffer);
        send(client_socket, buffer, bytes_received, 0); // Send back to client
    }
}

int conjure_socket() {
    int server_socket;
    struct sockaddr_in server_addr;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    return server_socket;
}

int conjure_client(int server_socket) {
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
        perror("Client accept failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("A client has entered the realm!\n");
    return client_socket;
}

void serve_clients(int server_socket) {
    while (1) {
        int client_socket = conjure_client(server_socket);
        mystic_echo(client_socket);
        close(client_socket);
        printf("A client has departed...\n");
    }
}

void exodus(int server_socket) {
    close(server_socket);
    printf("Server shutting down...\n");
}

int main() {
    int server_socket = conjure_socket();
    printf("Server ready at port %d...\n", PORT);
    serve_clients(server_socket);
    exodus(server_socket);
    return 0;
}