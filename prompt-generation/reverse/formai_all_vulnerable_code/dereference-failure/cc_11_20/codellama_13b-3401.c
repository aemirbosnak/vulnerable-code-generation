//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
/*
 * A POP3 client example program in C.
 * This program demonstrates how to connect to a POP3 server,
 * retrieve messages, and disconnect.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110
#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Get server and port from command-line arguments
    char *server = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read the initial greeting from the server
    char buffer[MAX_LINE_LEN];
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("read");
        return 1;
    }
    printf("Server greeting: %s\n", buffer);

    // Send the USER command
    char *cmd = "USER your_username";
    if (write(sock, cmd, strlen(cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read the response from the server
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("read");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send the PASS command
    cmd = "PASS your_password";
    if (write(sock, cmd, strlen(cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read the response from the server
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("read");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send the STAT command
    cmd = "STAT";
    if (write(sock, cmd, strlen(cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read the response from the server
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("read");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send the RETR command
    cmd = "RETR 1";
    if (write(sock, cmd, strlen(cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Read the response from the server
    if (read(sock, buffer, sizeof(buffer)) < 0) {
        perror("read");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Send the QUIT command
    cmd = "QUIT";
    if (write(sock, cmd, strlen(cmd)) < 0) {
        perror("write");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}