//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define DEFAULT_PORT 80
#define BUFFER_SIZE 1024

void scan_ports(int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (int i = start_port; i <= end_port; i++) {
        int port_open = 0;
        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(i);
        server.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", i);
            port_open = 1;
        } else {
            printf("Port %d is closed\n", i);
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage:./port_scanner start_port end_port\n");
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