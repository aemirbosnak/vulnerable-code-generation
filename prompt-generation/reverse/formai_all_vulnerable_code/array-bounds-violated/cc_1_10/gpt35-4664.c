//FormAI DATASET v1.0 Category: Socket programming ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 8080

void handle_connection(int client_socket);

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t address_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;
    memset(server_address.sin_zero, '\0', sizeof(server_address.sin_zero));

    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) == -1) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &address_size);
        if (client_socket == -1) {
            perror("Error accepting connection");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        handle_connection(client_socket);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}

void handle_connection(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received, bytes_sent;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s", buffer);

        bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Error sending message");
            return;
        }
    }

    if (bytes_received == -1) {
        perror("Error receiving message");
    }
}