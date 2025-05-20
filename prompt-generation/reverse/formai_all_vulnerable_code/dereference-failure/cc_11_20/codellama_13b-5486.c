//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Claude Shannon
// Simple HTTP Proxy Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        printf("Usage: %s <source_port> <target_port>\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    int source_port = atoi(argv[1]);
    int target_port = atoi(argv[2]);

    // Create socket for listening
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("socket");
        return 1;
    }

    // Bind socket to source port
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(source_port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    // Accept incoming connection
    int client_sock = accept(listen_sock, NULL, NULL);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Create socket for outgoing connection
    int target_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (target_sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to target host
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(target_port);
    target_addr.sin_addr.s_addr = INADDR_ANY;
    if (connect(target_sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Transfer data between client and target
    char buffer[BUFFER_SIZE];
    while (1) {
        // Receive data from client
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        // Send data to target
        int bytes_sent = send(target_sock, buffer, bytes_received, 0);
        if (bytes_sent <= 0) {
            break;
        }
    }

    // Close sockets
    close(listen_sock);
    close(client_sock);
    close(target_sock);

    return 0;
}