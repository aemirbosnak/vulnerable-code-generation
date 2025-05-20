//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: optimized
/*
 * Building a HTTP Client example program in an optimized style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Set up the TCP socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Set up the TCP connection
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        perror("inet_pton() failed");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Send the HTTP request
    char request[BUFSIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(sock, request, strlen(request), 0) < 0) {
        perror("send() failed");
        return 1;
    }

    // Receive the HTTP response
    char response[BUFSIZE];
    int bytes_received = recv(sock, response, BUFSIZE, 0);
    if (bytes_received < 0) {
        perror("recv() failed");
        return 1;
    }

    // Print the HTTP response
    printf("HTTP/1.1 %d %s\n", bytes_received, response);

    // Close the TCP connection
    close(sock);

    return 0;
}