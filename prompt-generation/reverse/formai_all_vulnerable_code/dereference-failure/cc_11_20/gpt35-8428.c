//FormAI DATASET v1.0 Category: Port Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int socket_fd, is_up, port, port_min, port_max, timeout;
    char *ip_addr_str;
    struct sockaddr_in srv_addr;
    struct hostent *host_info;

    // Validate input arguments
    if (argc < 3) {
        fprintf(stderr, "usage: %s <host> <port-range> [timeout]\n", argv[0]);
        fprintf(stderr, "\t<port-range> can be a single port (e.g. 22) or a range (e.g. 20-30)\n");
        fprintf(stderr, "\t<timeout> is optional and defaults to 1 second\n");
        exit(EXIT_FAILURE);
    }

    // Parse IP address and port range
    ip_addr_str = argv[1];
    char *hyphen_pos = strchr(argv[2], '-');
    if (hyphen_pos == NULL) {
        port_min = port_max = atoi(argv[2]);
    } else {
        *hyphen_pos = '\0';
        port_min = atoi(argv[2]);
        port_max = atoi(hyphen_pos+1);
        if (port_min > port_max) {
            fprintf(stderr, "Error: invalid port range specified\n");
            exit(EXIT_FAILURE);
        }
    }

    // Parse timeout if provided
    if (argc > 3) {
        timeout = atoi(argv[3]);
    } else {
        timeout = 1;
    }

    // Resolve IP address
    host_info = gethostbyname(ip_addr_str);
    if (host_info == NULL) {
        fprintf(stderr, "Error: could not resolve hostname \"%s\"\n", ip_addr_str);
        exit(EXIT_FAILURE);
    }

    // Copy IP address to sockaddr_in struct
    memset((char*)&srv_addr, 0, sizeof(srv_addr));
    memcpy((char*)&srv_addr.sin_addr.s_addr, (char*)host_info->h_addr, host_info->h_length);
    srv_addr.sin_family = AF_INET;

    // Loop through the port range and attempt connection to each port
    for (port = port_min; port <= port_max; port++) {
        is_up = 0;

        // Create socket
        socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd < 0) {
            fprintf(stderr, "Error: could not create socket\n");
            exit(EXIT_FAILURE);
        }

        // Set timeout for socket
        struct timeval tv;
        tv.tv_sec = timeout;
        tv.tv_usec = 0;
        if (setsockopt(socket_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
            fprintf(stderr, "Error: could not set socket timeout\n");
            exit(EXIT_FAILURE);
        }

        // Connect to server on specified port
        srv_addr.sin_port = htons(port);
        if (connect(socket_fd, (struct sockaddr*)&srv_addr, sizeof(srv_addr)) >= 0) {
            is_up = 1;
        }

        // Close socket and report result
        close(socket_fd);
        if (is_up) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    return 0;
}