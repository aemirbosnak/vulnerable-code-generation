//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
/*
 * A unique C TCP/IP Programming example program
 *
 * This program demonstrates a simple TCP/IP client-server
 * communication between two computers. The client sends a
 * request to the server, and the server responds with a
 * message.
 *
 * Usage:
 * ./tcp_client <server_ip> <server_port>
 *
 * Where <server_ip> is the IP address of the server, and
 * <server_port> is the port number of the server.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    // Get server IP and port
    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send request to server
    char request[MAX_BUFFER_SIZE];
    sprintf(request, "Hello, server!");
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response from server
    char response[MAX_BUFFER_SIZE];
    if (recv(sock, response, MAX_BUFFER_SIZE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    // Print response
    printf("Received response: %s\n", response);

    // Close socket
    close(sock);

    return 0;
}