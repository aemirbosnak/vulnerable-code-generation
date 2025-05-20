#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 16

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    printf("Client connected\n");

    // Vulnerability: Buffer overflow using gets()
    gets(buffer);

    printf("Received data: %s\n", buffer);
}

int main() {
    int server_socket = 1234; // Simulated server socket
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL); // Simulate accepting a client connection
        if (client_socket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }
    return 0;
}
