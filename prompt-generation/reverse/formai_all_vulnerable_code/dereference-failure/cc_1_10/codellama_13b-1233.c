//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
/*
 * HTTP client example program in a ephemeral style
 *
 * This program demonstrates how to build a simple HTTP client in C.
 * It sends a GET request to a specified URL and prints the response.
 *
 * Usage:
 *   ./http_client <url>
 *
 * Example:
 *   ./http_client https://www.example.com/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // Parse the URL to get the hostname and path
    char hostname[BUFSIZE];
    char path[BUFSIZE];
    sscanf(url, "%[^/]//%[^/]/%s", hostname, path);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Look up the hostname and get the IP address
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        perror("getaddrinfo");
        return 1;
    }

    // Connect to the server
    if (connect(sock, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        return 1;
    }

    // Free the address info
    freeaddrinfo(res);

    // Send the GET request
    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (write(sock, request, strlen(request)) < 0) {
        perror("write");
        return 1;
    }

    // Read the response
    char response[BUFSIZE];
    if (read(sock, response, BUFSIZE) < 0) {
        perror("read");
        return 1;
    }

    // Close the socket
    close(sock);

    // Print the response
    printf("Response: %s\n", response);

    return 0;
}