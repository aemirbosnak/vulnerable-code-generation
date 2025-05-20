//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void usage(char *program) {
    fprintf(stderr, "Usage: %s <IP Address> <Start Port> <End Port>\n", program);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        usage(argv[0]);
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    char buffer[1024];

    while (start_port <= end_port) {
        int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        if (result == 0) {
            snprintf(buffer, sizeof(buffer), "Port %d is open\n", start_port);
            write(1, buffer, strlen(buffer));
        } else if (errno == ECONNREFUSED) {
            snprintf(buffer, sizeof(buffer), "Port %d is closed\n", start_port);
            write(1, buffer, strlen(buffer));
        } else {
            snprintf(buffer, sizeof(buffer), "Error on port %d: %s\n", start_port, strerror(errno));
            write(2, buffer, strlen(buffer));
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);

        server_addr.sin_port = htons(++start_port);
    }

    close(sock);
    return 0;
}