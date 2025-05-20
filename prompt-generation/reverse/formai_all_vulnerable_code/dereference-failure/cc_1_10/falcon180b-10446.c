//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535

// Function to check if a port is open or not
int check_port(int sockfd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d\n", port);
        }
        close(sockfd);
        return -1;
    } else {
        printf("Port %d is open\n", port);
        close(sockfd);
        return 0;
    }
}

// Function to scan a range of ports
void scan_ports(int start_port, int end_port) {
    int sockfd;
    for (int i = start_port; i <= end_port; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        if (check_port(sockfd, i) == 0) {
            printf("Port %d is open\n", i);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage:./port_scanner <start_port> <end_port>\n");
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < PORT_RANGE_START || end_port > PORT_RANGE_END) {
        printf("Invalid port range\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d...\n", start_port, end_port);
    scan_ports(start_port, end_port);

    return 0;
}