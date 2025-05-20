//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

void scan_ports(int ip_address, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(ip_address);

    for (int port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        printf("Usage:./port_scanner <IP Address> <Start Port> <End Port>\n");
        return 1;
    }

    int ip_address = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (ip_address == INADDR_NONE) {
        printf("Invalid IP address\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Start port cannot be greater than end port\n");
        return 1;
    }

    if (start_port < 1 || end_port > MAX_PORT) {
        printf("Ports must be between 1 and %d\n", MAX_PORT);
        return 1;
    }

    scan_ports(ip_address, start_port, end_port);

    return 0;
}