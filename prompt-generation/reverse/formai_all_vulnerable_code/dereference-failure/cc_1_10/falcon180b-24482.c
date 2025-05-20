//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int port;
    for (port = start_port; port <= end_port; port++) {
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket == -1) {
            printf("Error creating socket\n");
            exit(1);
        }
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = target_ip;
        if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
            close(server_socket);
        } else {
            printf("Port %d is closed\n", port);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage:./port_scanner <target_ip> <start_port> <end_port>\n");
        return 1;
    }
    int target_ip = inet_addr(argv[1]);
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}