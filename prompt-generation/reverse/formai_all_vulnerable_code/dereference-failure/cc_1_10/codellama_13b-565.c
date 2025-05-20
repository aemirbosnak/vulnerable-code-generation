//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Bind the socket to the specified port
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen() failed");
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept() failed");
        return 1;
    }

    // Create a buffer to store incoming data
    char buffer[BUF_SIZE];
    int bytes_read;

    // Read data from the client
    bytes_read = recv(client_sock, buffer, BUF_SIZE, 0);
    if (bytes_read < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print the data to the console
    printf("Received %d bytes from client: %s\n", bytes_read, buffer);

    // Send a response back to the client
    char response[] = "Hello, client!";
    send(client_sock, response, strlen(response), 0);

    // Close the socket
    close(client_sock);
    close(server_sock);

    return 0;
}