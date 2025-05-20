//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];

    // Get host information
    struct addrinfo hints = {0};
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result;
    int s = getaddrinfo(hostname, "http", &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    // Find a suitable address to connect to
    struct sockaddr_in *addr;
    for (struct addrinfo *rp = result; rp != NULL; rp = rp->ai_next) {
        if (rp->ai_family == AF_INET) {
            addr = (struct sockaddr_in *) rp->ai_addr;
            break;
        }
    }

    // Create a socket and connect to the server
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *) addr, sizeof(struct sockaddr_in)) < 0) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\n" \
                    "Host: %s\r\n" \
                    "Connection: close\r\n" \
                    "\r\n";
    char buffer[BUFFER_SIZE];
    int len = snprintf(buffer, BUFFER_SIZE, request, hostname);
    if (len >= BUFFER_SIZE) {
        fprintf(stderr, "request too long\n");
        exit(EXIT_FAILURE);
    }

    if (write(sock, buffer, len) < 0) {
        fprintf(stderr, "write error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive HTTP response
    while (1) {
        int n = read(sock, buffer, BUFFER_SIZE - 1);
        if (n < 0) {
            fprintf(stderr, "read error: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            break;
        }

        buffer[n] = '\0';
        printf("%s", buffer);
    }

    // Clean up
    freeaddrinfo(result);
    close(sock);
    exit(EXIT_SUCCESS);
}