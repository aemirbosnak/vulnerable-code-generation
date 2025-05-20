//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535 // Maximum number of ports to scan
#define BUF_SIZE 1024 // Size of buffer to store response

// Function to print usage instructions
void print_usage() {
    printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
}

// Function to scan a single port
int scan_port(int sock, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
        printf("Port %d is open\n", port);
        close(sock);
        return 1;
    } else {
        printf("Port %d is closed\n", port);
        close(sock);
        return 0;
    }
}

// Function to scan a range of ports
void scan_ports(char *ip_addr, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0); // Create socket
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    for (int port = start_port; port <= end_port; port++) {
        int result = scan_port(sock, port);
        if (result == 1) {
            printf("Open ports:\n");
        }
    }

    close(sock); // Close socket
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        exit(1);
    }

    char *ip_addr = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(ip_addr, start_port, end_port);

    return 0;
}