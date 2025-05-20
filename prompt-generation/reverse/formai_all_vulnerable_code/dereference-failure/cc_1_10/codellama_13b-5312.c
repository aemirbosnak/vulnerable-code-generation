//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

#define MAX_PORTS 100
#define MAX_HOSTS 100
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    int port_range = atoi(argv[1]);
    if (port_range < 0 || port_range > 65535) {
        printf("Invalid port range: %d\n", port_range);
        return 1;
    }

    struct sockaddr_in server;
    struct hostent *host;
    int sock, n, i, port;
    char buffer[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    host = gethostbyname("localhost");
    if (host == NULL) {
        printf("Error getting host information: %s\n", hstrerror(h_errno));
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port_range);
    server.sin_addr = *((struct in_addr *) host->h_addr);

    for (port = 0; port < port_range; port++) {
        printf("Scanning port %d...\n", port);

        if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }

        close(sock);
    }

    return 0;
}