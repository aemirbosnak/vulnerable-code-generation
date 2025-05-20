//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT_RANGE_MIN 1
#define PORT_RANGE_MAX 65535

void print_usage(char* program_name) {
    printf("Usage: %s <host> <port_range>\n", program_name);
    printf("Example: %s google.com 80-443\n", program_name);
    exit(1);
}

int is_valid_port(int port) {
    if (port < PORT_RANGE_MIN || port > PORT_RANGE_MAX) {
        return 0;
    }
    return 1;
}

int is_port_open(int sock, int port) {
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    int result = connect(sock, (struct sockaddr*)&server, sizeof(server));
    if (result == -1) {
        close(sock);
        return 0;
    } else {
        close(sock);
        return 1;
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char* host = argv[1];
    char* port_range = argv[2];
    int port_min, port_max;
    sscanf(port_range, "%d-%d", &port_min, &port_max);

    if (port_min > port_max) {
        printf("Invalid port range\n");
        return 1;
    }

    for (int port = port_min; port <= port_max; port++) {
        if (!is_valid_port(port)) {
            continue;
        }

        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket\n");
            return 1;
        }

        if (is_port_open(sock, port)) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        close(sock);
    }

    return 0;
}