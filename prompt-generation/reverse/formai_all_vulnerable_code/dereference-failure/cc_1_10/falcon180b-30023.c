//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sock, port, result;
    struct hostent *host;
    struct sockaddr_in target;
    char *ip_address;
    int opt = 1;
    char *ptr;

    // Check if the correct number of arguments are provided
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        exit(1);
    }

    // Set the IP address
    ip_address = argv[1];

    // Set the port range
    port = atoi(argv[2]);

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket()");
        exit(1);
    }

    // Set the socket options
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt()");
        exit(1);
    }

    // Get the host information
    host = gethostbyname(ip_address);

    if (host == NULL) {
        printf("Invalid IP address\n");
        exit(1);
    }

    // Fill in the target structure
    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_port = htons(port);
    memcpy(&target.sin_addr.s_addr, host->h_addr, host->h_length);

    // Loop through the port range
    for (port = 1; port <= 65535; port++) {
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
    return 0;
}