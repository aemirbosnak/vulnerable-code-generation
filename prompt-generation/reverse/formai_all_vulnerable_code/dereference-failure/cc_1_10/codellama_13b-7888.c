//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check for the correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse the port number
    int port = atoi(argv[1]);
    if (port == 0) {
        printf("Invalid port number\n");
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Receive a message from the client
    char buffer[256];
    ssize_t n = recv(client_sock, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Send a response to the client
    char response[] = "Hello, client!";
    ssize_t m = send(client_sock, response, strlen(response), 0);
    if (m < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(client_sock);

    return 0;
}