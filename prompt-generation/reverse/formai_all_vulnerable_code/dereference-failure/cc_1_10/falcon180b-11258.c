//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    char buffer[BUF_SIZE];
    int bytes_received;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8000);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for connections
    if (listen(server_socket, 5) == -1) {
        printf("Error listening: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        // Accept connection
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from client
        bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data: %s\n", strerror(errno));
            exit(1);
        }

        printf("Received %d bytes of data: %s\n", bytes_received, buffer);

        // Send data to client
        strcpy(buffer, "Hello, client!");
        send(client_socket, buffer, strlen(buffer), 0);

        close(client_socket);
    }

    close(server_socket);

    return 0;
}