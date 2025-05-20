//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT_RANGE_START 1
#define PORT_RANGE_END 65535
#define BUFFER_SIZE 1024

void print_help() {
    printf("Usage:./scanner <host> <port_range> \n");
    printf("Example:./scanner localhost 1-1000\n");
}

int is_port_open(int sock, int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (result == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        print_help();
        return 1;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Failed to create socket\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    for (int port = start_port; port <= end_port; port++) {
        sprintf(buffer, "Scanning port %d...\n", port);
        write(1, buffer, strlen(buffer));

        if (is_port_open(sock, port)) {
            sprintf(buffer, "Port %d is open\n", port);
        } else {
            sprintf(buffer, "Port %d is closed\n", port);
        }

        write(1, buffer, strlen(buffer));
    }

    close(sock);
    return 0;
}