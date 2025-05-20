//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to print the usage of the program
void print_usage(char *program_name) {
    printf("Usage: %s <IP address> <port range>\n", program_name);
    printf("Example: %s 192.168.0.1 1-65535\n", program_name);
    exit(1);
}

// Function to check if a port is open or not
int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    int result = connect(sock, (struct sockaddr *)&server, sizeof(server));

    if (result == 0) {
        close(sock);
        return 1;
    } else if (errno == ECONNREFUSED) {
        close(sock);
        return 0;
    } else {
        close(sock);
        return -1;
    }
}

// Function to scan a range of ports
void scan_ports(char *ip_address, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        int result = check_port(sock, port);

        if (result == 1) {
            printf("%d - Open\n", port);
        } else if (result == 0) {
            printf("%d - Closed\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}