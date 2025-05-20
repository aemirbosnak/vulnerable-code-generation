//Code Llama-13B DATASET v1.0 Category: Simple Web Server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock, client_sock;
    struct sockaddr_in server, client;
    char buffer[1024] = {0};
    int client_len = sizeof(client);

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket()");
        return 1;
    }

    // Set address information
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    // Bind socket
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind()");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen()");
        return 1;
    }

    printf("Server listening on port %d...\n", atoi(argv[1]));

    // Accept incoming connections
    while (1) {
        if ((client_sock = accept(sock, (struct sockaddr *)&client, (socklen_t *)&client_len)) < 0) {
            perror("accept()");
            return 1;
        }

        printf("New connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));

        // Receive data from client
        if (recv(client_sock, buffer, 1024, 0) < 0) {
            perror("recv()");
            return 1;
        }

        // Print data
        printf("Received data: %s\n", buffer);

        // Send response
        if (send(client_sock, "Hello, client!", 13, 0) < 0) {
            perror("send()");
            return 1;
        }

        printf("Response sent.\n");

        // Close connection
        if (close(client_sock) < 0) {
            perror("close()");
            return 1;
        }

        printf("Connection closed.\n");
    }

    // Close socket
    if (close(sock) < 0) {
        perror("close()");
        return 1;
    }

    return 0;
}