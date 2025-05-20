//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to check if a port is open or not
int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (inet_pton(AF_INET, "127.0.0.1", &server.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        return -1;
    }

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (result == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
        close(sock);
    }
    return result;
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        int result = check_port(sock, i);
        if (result == -1) {
            break;
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <start_port> <end_port>\n");
        return 1;
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(start_port, end_port);

    return 0;
}