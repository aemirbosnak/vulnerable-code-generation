//Code Llama-13B DATASET v1.0 Category: Networking ; Style: realistic
/*
 * Example C Networking Program
 *
 * This program demonstrates how to use the C programming language to create a
 * simple client-server network application. The client sends a message to the
 * server, which then responds with a message of its own. The client then
 * prints the response to the console.
 *
 * Usage:
 * 1. Compile this code with a C compiler (e.g. gcc)
 * 2. Run the resulting executable with the command-line arguments:
 *    <hostname> <port>
 *    where <hostname> is the hostname of the server and <port> is the port
 *    number of the server
 *
 * Example:
 * $ ./client localhost 8080
 *
 * This will connect to a server running on the local machine at port 8080
 * and send the message "Hello, server!" to the server. The server will
 * respond with a message of its own, which will be printed to the console.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_LEN 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Get hostname and port from command-line arguments
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket for communicating with the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the message to the server
    char msg[] = "Hello, server!";
    if (send(sock, msg, strlen(msg), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    char buffer[MAX_MSG_LEN];
    if (recv(sock, buffer, MAX_MSG_LEN, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the response to the console
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}