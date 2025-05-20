//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    if(start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);

    for(int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if(connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else if(errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error on port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
    return 0;
}