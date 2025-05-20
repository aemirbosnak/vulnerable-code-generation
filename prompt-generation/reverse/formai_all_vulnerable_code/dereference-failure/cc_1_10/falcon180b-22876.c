//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 65535
#define TRUE 1
#define FALSE 0
#define BUF_SIZE 1024

int check_port(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        close(sock);
        return FALSE;
    } else {
        close(sock);
        return TRUE;
    }
}

void scan_ports(int start_port, int end_port) {
    int sock, port;
    char buffer[BUF_SIZE];

    for (port = start_port; port <= end_port; port++) {
        sock = socket(AF_INET, SOCK_STREAM, 0);

        if (sock == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        if (check_port(sock, port)) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        close(sock);
    }
}

int main(int argc, char *argv[]) {
    int start_port, end_port;

    if (argc!= 4) {
        printf("Usage: %s <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    start_port = atoi(argv[1]);
    end_port = atoi(argv[2]);

    if (start_port > end_port || start_port < 1 || end_port > MAX) {
        printf("Invalid port range\n");
        return 1;
    }

    scan_ports(start_port, end_port);

    return 0;
}