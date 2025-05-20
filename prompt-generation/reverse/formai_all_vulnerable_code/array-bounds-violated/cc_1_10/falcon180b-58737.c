//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int bytes_received;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        error_handling("socket failed");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    // Bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        error_handling("listen failed");
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        // Accept a connection
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            error_handling("accept failed");
        }

        printf("Connection accepted\n");

        // Receive data from client
        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            // Send response to client
            if (send(client_socket, "Message received", strlen("Message received"), 0) < 0) {
                error_handling("send failed");
            }
        }

        close(client_socket);
        printf("Connection closed\n");
    }

    close(server_socket);
    return 0;
}