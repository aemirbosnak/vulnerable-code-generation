//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: active
/*
 * PortScanner.c
 * A simple port scanner written in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_PORTS 65535

int main(int argc, char **argv) {
    // Check the number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port range
    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Check the validity of the port range
    if (start_port < 0 || end_port > MAX_PORTS || start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Initialize the sockaddr structure
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    server.sin_addr.s_addr = inet_addr(ip_address);

    // Loop through the port range
    for (int i = start_port; i <= end_port; i++) {
        // Set the port number
        server.sin_port = htons(i);

        // Connect to the server
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
            perror("connect");
            close(sock);
            exit(EXIT_FAILURE);
        }

        // Print the open port
        printf("Port %d is open\n", i);

        // Close the socket
        close(sock);
    }

    return 0;
}