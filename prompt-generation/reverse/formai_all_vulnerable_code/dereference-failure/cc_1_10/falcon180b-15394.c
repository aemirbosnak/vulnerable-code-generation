//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(int sock, int target_ip, int start_port, int end_port)
{
    int port;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    for (port = start_port; port <= end_port; port++) {
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = target_ip;

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open on %s\n", port, inet_ntoa(server_addr.sin_addr));
        } else {
            printf("Port %d is closed on %s\n", port, inet_ntoa(server_addr.sin_addr));
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        return 1;
    }

    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (target_ip == INADDR_NONE) {
        printf("Invalid target IP address\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);

    return 0;
}