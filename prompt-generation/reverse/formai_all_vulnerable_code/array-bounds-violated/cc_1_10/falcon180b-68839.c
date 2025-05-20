//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error_handling("socket failed");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
        exit(1);
    }

    // Listen
    if (listen(server_socket, 5) == -1) {
        error_handling("listen failed");
        exit(1);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    // Accept a connection
    socklen_t addr_size = sizeof(client_addr);
    client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
    if (client_socket == -1) {
        error_handling("accept failed");
        exit(1);
    }

    // Receive data from client
    int bytes_received = 0;
    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        // Send response to client
        send(client_socket, "Message received", strlen("Message received"), 0);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}