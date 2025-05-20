//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int bytes_received;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen on socket
    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    // Accept client connection
    client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
    if (client_socket == -1) {
        printf("Error accepting client connection: %s\n", strerror(errno));
        exit(1);
    }

    printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Send welcome message to client
    send(client_socket, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

    // Receive data from client
    while (1) {
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    // Close sockets
    close(server_socket);
    close(client_socket);

    return 0;
}