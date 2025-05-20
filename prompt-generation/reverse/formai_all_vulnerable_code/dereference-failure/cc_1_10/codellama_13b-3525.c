//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 1000
#define MAX_HOSTS 100
#define BUF_SIZE 1024

int main(int argc, char **argv) {
    // Check for valid arguments
    if (argc < 2) {
        printf("Usage: %s <host> [port]\n", argv[0]);
        return 1;
    }

    // Parse host and port
    char *host = argv[1];
    int port = (argc > 2) ? atoi(argv[2]) : 0;

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Create a sockaddr_in struct
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the host
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Check if the port is open
    if (is_port_open(sock)) {
        printf("Port %d is open\n", port);
    } else {
        printf("Port %d is closed\n", port);
    }

    // Close the socket
    close(sock);

    return 0;
}

int is_port_open(int sock) {
    // Create a char buffer
    char buf[BUF_SIZE];

    // Send a test message
    int ret = send(sock, "test", strlen("test"), 0);
    if (ret < 0) {
        perror("send");
        return 0;
    }

    // Receive the response
    ret = recv(sock, buf, BUF_SIZE, 0);
    if (ret < 0) {
        perror("recv");
        return 0;
    }

    // Check if the response is valid
    if (strcmp(buf, "test") == 0) {
        return 1;
    } else {
        return 0;
    }
}