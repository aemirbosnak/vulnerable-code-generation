//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server_ip_address>\n", argv[0]);
        return 1;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(DEFAULT_PORT);

    if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating client socket");
        return 1;
    }

    struct sockaddr_in client_address;
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = INADDR_ANY;
    client_address.sin_port = htons(DEFAULT_PORT);

    if (bind(client_socket, (struct sockaddr *)&client_address, sizeof(client_address)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(client_socket, 1) < 0) {
        perror("Error listening for client requests");
        return 1;
    }

    printf("Proxy server running on port %d\n", DEFAULT_PORT);

    char buffer[BUFFER_SIZE];
    int message_size;

    while (1) {
        int client_connection = accept(client_socket, (struct sockaddr *)NULL, NULL);
        if (client_connection < 0) {
            perror("Error accepting client connection");
            continue;
        }

        message_size = recv(client_connection, buffer, BUFFER_SIZE, 0);
        if (message_size < 0) {
            perror("Error receiving client request");
            continue;
        }

        buffer[message_size] = 0;
        printf("Received client request:\n%s", buffer);

        if (send(server_socket, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending request to server");
            continue;
        }

        message_size = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (message_size < 0) {
            perror("Error receiving response from server");
            continue;
        }

        if (send(client_connection, buffer, message_size, 0) < 0) {
            perror("Error sending response to client");
            continue;
        }

        buffer[message_size] = 0;
        printf("Sent response to client:\n%s", buffer);

        close(client_connection);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}