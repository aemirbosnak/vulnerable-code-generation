//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
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
    int sock;
    struct sockaddr_in server;
    int port;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(sock);
        return 1;
    }

    for (port = 1; port <= MAX_PORTS; port++) {
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            return 0;
        } else if (errno!= ECONNREFUSED) {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
            close(sock);
            return 1;
        }
    }

    printf("No open ports found in range %s\n", argv[2]);
    close(sock);
    return 0;
}