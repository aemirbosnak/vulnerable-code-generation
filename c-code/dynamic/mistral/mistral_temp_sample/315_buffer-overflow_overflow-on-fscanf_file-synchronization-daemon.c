#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int n = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (n > 0) {
        buffer[n] = '\0'; // Assume no need for null termination after checking n > 0
        fscanf(stdin, "%s", buffer); // Intentional buffer overflow in fscanf
        printf("Received from client: %s\n", buffer);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Initialize addresses
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Bind socket
    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for connections
    listen(server_socket, 3);

    printf("Listening on port %d...\n", PORT);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        handle_client(client_socket);
    }

    return 0;
}
