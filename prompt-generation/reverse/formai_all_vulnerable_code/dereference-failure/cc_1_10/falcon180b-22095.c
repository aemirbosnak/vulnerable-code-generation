//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <errno.h>

#define MAX_PORTS 65535
#define TIMEOUT 5000 // 5 seconds

void print_usage(char *prog_name) {
    fprintf(stderr, "Usage: %s <ip_address> <start_port> <end_port>\n", prog_name);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &serv_addr.sin_addr);

    int addrlen = sizeof(serv_addr);

    int timeout = TIMEOUT;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    for (int port = start_port; port <= end_port; port++) {
        serv_addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&serv_addr, addrlen) == 0) {
            printf("Port %d is open\n", port);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", port);
        } else if (errno == ETIMEDOUT) {
            printf("Connection timed out for port %d\n", port);
        } else {
            printf("Error connecting to port %d: %s\n", port, strerror(errno));
        }
    }

    close(sock);
    return 0;
}