//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: optimized
/*
 * smtp_client.c
 *
 * A simple SMTP client example program in an optimized style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char **argv) {
    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Set up the server address and port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HELO command
    char cmd[MAX_BUF_SIZE];
    snprintf(cmd, MAX_BUF_SIZE, "HELO %s\r\n", argv[1]);
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    char buf[MAX_BUF_SIZE];
    if (recv(sock, buf, MAX_BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the server response
    printf("Server response: %s\n", buf);

    // Send the QUIT command
    snprintf(cmd, MAX_BUF_SIZE, "QUIT\r\n");
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    if (close(sock) < 0) {
        perror("close");
        return 1;
    }

    return 0;
}