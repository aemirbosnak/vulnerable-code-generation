//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_PORTS 65535
#define TIMEOUT 5000 // 5 seconds

// Function to print usage instructions
void print_usage() {
    printf("Usage:./portscanner <IP Address> <Start Port> <End Port>\n");
}

// Function to check if a port is open
int check_port(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
        close(sock);
        return 1; // Port is open
    } else {
        return 0; // Port is closed
    }
}

// Function to scan ports
void scan_ports(char *ip, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server.sin_addr);

    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    for (int i = start_port; i <= end_port; i++) {
        if (check_port(sock, i) == 1) {
            printf("Port %d is open.\n", i);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage();
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range.\n");
        return 1;
    }

    scan_ports(ip, start_port, end_port);

    return 0;
}