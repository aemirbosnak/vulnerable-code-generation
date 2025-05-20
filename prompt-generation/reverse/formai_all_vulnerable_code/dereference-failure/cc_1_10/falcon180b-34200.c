//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_PORT 65535
#define BUFFER_SIZE 1024

void scan_ports(char *ip_address, int start_port, int end_port);

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(ip_address, start_port, end_port);

    return 0;
}

void scan_ports(char *ip_address, int start_port, int end_port) {
    int sock;
    struct sockaddr_in server;
    struct hostent *host;
    int port;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        return;
    }

    host = gethostbyname(ip_address);

    if (host == NULL) {
        printf("Error resolving hostname\n");
        close(sock);
        return;
    }

    memcpy(&server.sin_addr, host->h_addr, host->h_length);
    server.sin_family = AF_INET;
    server.sin_port = htons(start_port);

    for (port = start_port; port <= end_port; port++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            printf("Port %d is closed\n", port);
        }
        server.sin_port = htons(port + 1);
    }

    close(sock);
}