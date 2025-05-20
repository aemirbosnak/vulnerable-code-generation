//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: Ken Thompson
// A unique C Network Packet Monitoring example program in a Ken Thompson style
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Convert port string to integer
    int port = atoi(argv[1]);
    if (port < 1 || port > 65535) {
        fprintf(stderr, "Invalid port: %s\n", argv[1]);
        exit(1);
    }

    // Create a socket for listening
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the port
    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Listening on port %d...\n", port);

    // Create a buffer for incoming data
    char buf[1024];

    // Accept incoming connections
    while (1) {
        // Accept a new connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            continue;
        }

        // Receive data from the client
        int n = recv(client_sock, buf, 1024, 0);
        if (n < 0) {
            perror("recv");
            continue;
        }

        // Print the data to the console
        printf("Received %d bytes from client: %s\n", n, buf);

        // Close the connection
        close(client_sock);
    }

    // Close the socket
    close(sock);

    return 0;
}