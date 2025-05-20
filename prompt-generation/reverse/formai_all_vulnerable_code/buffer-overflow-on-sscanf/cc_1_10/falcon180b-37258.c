//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;

    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid port range\n");
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

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            if (errno == ECONNREFUSED) {
                printf("%d - Closed\n", port);
            } else {
                printf("%d - Error\n", port);
            }
        } else {
            printf("%d - Open\n", port);
            close(sock);
        }
    }

    return 0;
}