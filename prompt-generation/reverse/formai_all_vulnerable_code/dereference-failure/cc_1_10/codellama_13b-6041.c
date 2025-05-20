//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
/*
 * Example C Network Ping Test Program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define HOSTNAME "www.google.com"
#define PORT 80

int main() {
    struct addrinfo hints;
    struct addrinfo *server_info;
    int sock_fd;
    char send_buf[1024];
    char recv_buf[1024];
    int n;

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    // Get address info for hostname and port
    if (getaddrinfo(HOSTNAME, PORT, &hints, &server_info) != 0) {
        fprintf(stderr, "Error: getaddrinfo() failed\n");
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sock_fd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sock_fd < 0) {
        fprintf(stderr, "Error: socket() failed\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sock_fd, server_info->ai_addr, server_info->ai_addrlen) < 0) {
        fprintf(stderr, "Error: connect() failed\n");
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    sprintf(send_buf, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", HOSTNAME);
    send(sock_fd, send_buf, strlen(send_buf), 0);

    // Receive HTTP response
    n = recv(sock_fd, recv_buf, sizeof(recv_buf), 0);
    if (n < 0) {
        fprintf(stderr, "Error: recv() failed\n");
        exit(EXIT_FAILURE);
    }

    // Print HTTP response
    printf("%s\n", recv_buf);

    // Clean up
    close(sock_fd);
    freeaddrinfo(server_info);

    return 0;
}