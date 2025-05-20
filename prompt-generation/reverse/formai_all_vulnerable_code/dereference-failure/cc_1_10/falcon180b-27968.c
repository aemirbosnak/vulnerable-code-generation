//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    struct hostent *host;
    int sock, port, res;
    char *host_name;
    char buffer[1024];

    // Check if the user provided a hostname as an argument
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Get the IP address of the hostname
    host_name = argv[1];
    host = gethostbyname(host_name);
    if (host == NULL) {
        printf("Host not found.\n");
        exit(1);
    }

    // Loop through all ports from 1 to 65535
    for (port = 1; port <= 65535; port++) {
        // Create a socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Could not create socket.\n");
            exit(1);
        }

        // Set the timeout for each connection attempt
        struct timeval tv;
        tv.tv_sec = 5;
        tv.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (char *)&tv, sizeof(tv));
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

        // Connect to the host on the current port
        inet_ntop(AF_INET, &((struct sockaddr_in *)host->h_addr)->sin_addr, buffer, sizeof(buffer));
        printf("Testing port %d on %s...\n", port, buffer);
        res = connect(sock, host->h_addr, sizeof(struct sockaddr_in));

        // Check if the connection was successful
        if (res == -1) {
            close(sock);
            printf("Port %d is closed.\n", port);
        } else {
            close(sock);
            printf("Port %d is open.\n", port);
        }
    }

    return 0;
}