//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: all-encompassing
/*
 * A simple port scanner written in C
 *
 * Usage: port_scanner [host] [start_port] [end_port]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: port_scanner [host] [start_port] [end_port]\n");
        return 1;
    }

    char *host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket's address structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(start_port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Scan the ports
    int port = start_port;
    while (port <= end_port) {
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
        port++;
    }

    // Close the socket
    close(sock);
    return 0;
}