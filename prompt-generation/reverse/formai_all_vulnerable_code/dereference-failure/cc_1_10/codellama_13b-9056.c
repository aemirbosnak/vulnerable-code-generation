//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address
    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *) &client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Read from client
    char buf[BUF_SIZE];
    int n = read(client_sock, buf, BUF_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Print received message
    printf("Received message: %s\n", buf);

    // Send response to client
    char *resp = "Thank you for connecting!";
    if (write(client_sock, resp, strlen(resp)) < 0) {
        perror("write");
        return 1;
    }

    // Close client socket
    if (close(client_sock) < 0) {
        perror("close");
        return 1;
    }

    // Close server socket
    if (close(sock) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}