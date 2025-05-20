//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: satisfied
// Building a HTTP Client example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Get the hostname
    char *hostname = argv[1];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Get the address info
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    struct addrinfo *result;
    if (getaddrinfo(hostname, NULL, &hints, &result) != 0) {
        fprintf(stderr, "getaddrinfo failed\n");
        return 1;
    }

    // Connect to the server
    if (connect(sock, result->ai_addr, result->ai_addrlen) < 0) {
        perror("connect");
        return 1;
    }

    // Send a GET request
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    char req_buf[MAX_BUF_SIZE];
    snprintf(req_buf, MAX_BUF_SIZE, request, hostname);
    write(sock, req_buf, strlen(req_buf));

    // Read the response
    char buf[MAX_BUF_SIZE];
    int n = read(sock, buf, MAX_BUF_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }

    // Print the response
    printf("%s", buf);

    // Clean up
    close(sock);
    freeaddrinfo(result);

    return 0;
}