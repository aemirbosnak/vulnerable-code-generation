//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function prototypes
void scan_ports(int sock, int target_ip, int start_port, int end_port);
int create_socket();
int connect_to_target(int sock, int target_ip);

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int sock = create_socket();

    if (connect_to_target(sock, target_ip) == -1) {
        printf("Connection failed.\n");
        close(sock);
        return 1;
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return -1;
    }
    return sock;
}

int connect_to_target(int sock, int target_ip) {
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = target_ip;
    target_addr.sin_port = htons(0);

    if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1) {
        printf("Error connecting to target.\n");
        return -1;
    }

    return 0;
}

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = target_ip;
        target_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }
    }
}