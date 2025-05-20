//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
/*
 * Building a HTTP Client in C
 * Optimized style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a GET request to the server
    char *request = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server response
    char buf[MAX_BUF];
    int n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    // Print the response
    printf("%s", buf);

    // Close the socket
    close(sock);

    return 0;
}