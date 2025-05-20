//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
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
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    struct in_addr server_addr;
    if (inet_pton(AF_INET, ip_address, &server_addr) <= 0) {
        printf("Invalid IP Address\n");
        return 1;
    }

    int start_port, end_port;
    if (sscanf(port_range, "%d-%d", &start_port, &end_port)!= 2) {
        printf("Invalid Port Range\n");
        return 1;
    }

    if (start_port > end_port) {
        printf("Invalid Port Range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in server_socket;
        server_socket.sin_family = AF_INET;
        server_socket.sin_port = htons(port);
        server_socket.sin_addr.s_addr = server_addr.s_addr;

        if (connect(sock, (struct sockaddr *)&server_socket, sizeof(server_socket)) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Error connecting to port %d\n", port);
        }
    }

    close(sock);

    return 0;
}