//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
// scalable_tcp_ip_example.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 100
#define MAX_BUFFER 1024

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Bind socket
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind() failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen() failed");
        return 1;
    }

    // Accept incoming connections
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept() failed");
        return 1;
    }

    // Receive message from client
    char buffer[MAX_BUFFER];
    int n = recv(client_sock, buffer, MAX_BUFFER, 0);
    if (n < 0) {
        perror("recv() failed");
        return 1;
    }

    // Process message
    printf("Received message: %s\n", buffer);

    // Send response to client
    char response[] = "Hello, client!";
    if (send(client_sock, response, strlen(response), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Close client socket
    close(client_sock);

    // Close server socket
    close(sock);

    return 0;
}