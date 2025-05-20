//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Failed to listen on socket\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Waiting for connection...\n");
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Failed to accept connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        do {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected or error occurred\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received from client: %s\n", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        } while (1);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}