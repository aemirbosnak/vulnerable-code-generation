//FormAI DATASET v1.0 Category: Port Scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    // check if user provided correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <target ip> <port range>\n", argv[0]);
        printf("Example: %s 192.168.0.1 1-1024\n", argv[0]);
        return 0;
    }

    // parse target ip address
    struct in_addr ip_addr;
    if (inet_aton(argv[1], &ip_addr) == 0) {
        printf("Invalid ip address\n");
        return 0;
    }

    // parse port range
    char *port_range_str = argv[2];
    char *dash_ptr = strchr(port_range_str, '-');
    if (dash_ptr == NULL) {
        printf("Invalid port range\n");
        return 0;
    }
    int start_port = atoi(port_range_str);
    int end_port = atoi(dash_ptr + 1);
    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535) {
        printf("Invalid port range\n");
        return 0;
    }

    // create socket
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("Failed to create socket\n");
        return 0;
    }

    // set socket options
    int on = 1;
    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1) {
        printf("Failed to set socket options\n");
        close(sock_fd);
        return 0;
    }

    // connect to target
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port   = htons(start_port);
    target_addr.sin_addr   = ip_addr;

    bool any_port_opened = false;

    for (int port = start_port; port <= end_port; ++port) {
        target_addr.sin_port = htons(port);
        int rc = connect(sock_fd, (struct sockaddr*)&target_addr, sizeof(target_addr));
        if (rc == 0) {
            printf("Port %d opened\n", port);
            any_port_opened = true;
        }
    }

    if (!any_port_opened) {
        printf("No open ports found\n");
    }

    // close socket
    close(sock_fd);

    return 0;
}