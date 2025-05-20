//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

// Function to perform a TCP connect scan on a given IP address and port range
void tcp_connect_scan(const char *ip_address, int start_port, int end_port) {
    int sock = -1;
    struct sockaddr_in server_addr;
    int result;
    int port;

    for (port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (result == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }

        close(sock);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    const char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Start port cannot be greater than end port\n");
        return 1;
    }

    if (start_port < PORT_RANGE_MIN || end_port > PORT_RANGE_MAX) {
        printf("Port range must be between %d and %d\n", PORT_RANGE_MIN, PORT_RANGE_MAX);
        return 1;
    }

    printf("Performing TCP connect scan on %s:%d-%d...\n", ip_address, start_port, end_port);
    tcp_connect_scan(ip_address, start_port, end_port);

    return 0;
}