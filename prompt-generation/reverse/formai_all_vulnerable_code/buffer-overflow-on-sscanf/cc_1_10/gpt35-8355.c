//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define some color codes for a more cheerful output
#define MAGENTA "\x1B[35m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define RESET   "\x1B[0m"

// Function to check if a port is open
int is_port_open(char* ip, int port) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    int ret = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
    close(sock);
    return ret == 0;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port range>\n", argv[0]);
        return 1;
    }
    char* ip = argv[1];
    char* port_range = argv[2];
    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port) != 2) { // parse a range of ports
        printf("%sInvalid port range: %s%s\n", MAGENTA, port_range, RESET);
        return 1;
    }
    printf("%sScanning %s from port %d to port %d...%s\n", YELLOW, ip, start_port, end_port, RESET);
    for (int port = start_port; port <= end_port; port++) {
        if (is_port_open(ip, port)) {
            printf("%sPort %d is open!%s\n", GREEN, port, RESET);
        }
    }
    printf("%sScan completed.%s\n", YELLOW, RESET);
    return 0;
}