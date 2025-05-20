//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    for (int port = start_port; port <= end_port; port++) {
        if (port == start_port) {
            printf("Scanning port %d...\n", port);
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (result == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            return 0;
        } else if (result!= -1) {
            printf("Error connecting to port %d\n", port);
            close(sock);
            return 1;
        }
    }

    printf("All ports between %d and %d are closed\n", start_port, end_port);
    close(sock);
    return 0;
}