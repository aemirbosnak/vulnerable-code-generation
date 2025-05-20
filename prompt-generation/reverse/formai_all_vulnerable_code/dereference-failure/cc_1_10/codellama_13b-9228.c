//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PORTS 1024
#define MAX_IPS 100

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc < 3) {
        printf("Usage: %s <ip> <port_range_start> <port_range_end>\n", argv[0]);
        return 1;
    }

    // Get the IP address and port range from the command line arguments
    char *ip = argv[1];
    int port_range_start = atoi(argv[2]);
    int port_range_end = atoi(argv[3]);

    // Create a socket for connecting to the IP address
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Set the IP address and port range for the socket
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_range_start);
    addr.sin_addr.s_addr = inet_addr(ip);

    // Loop through the port range and try to connect to each port
    for (int port = port_range_start; port <= port_range_end; port++) {
        // Set the port for the socket
        addr.sin_port = htons(port);

        // Try to connect to the port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}