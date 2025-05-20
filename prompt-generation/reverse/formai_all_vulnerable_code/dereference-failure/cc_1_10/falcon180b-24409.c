//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_usage(char *argv[]) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
}

int is_valid_port(int port) {
    if (port < 1 || port > MAX_PORTS) {
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port range specified.\n");
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            return 1;
        }
    }

    close(sock);
    return 0;
}