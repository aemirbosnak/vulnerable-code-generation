//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: grateful
/*
 * Port Scanner in C
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check if the input is valid
    if (argc < 3) {
        printf("Usage: %s <ip_address> <port_range>\n", argv[0]);
        return 1;
    }

    // Get the IP address and port range from the input
    char *ip_address = argv[1];
    int port_range = atoi(argv[2]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: Cannot create socket\n");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        printf("Error: Cannot set socket options\n");
        return 1;
    }

    // Set the IP address and port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port_range);
    inet_pton(AF_INET, ip_address, &addr.sin_addr);

    // Loop through the port range
    for (int i = 0; i < port_range; i++) {
        // Connect to the socket
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            // Print the open port
            printf("Port %d is open\n", ntohs(addr.sin_port));
            break;
        }

        // Increment the port number
        addr.sin_port = htons(ntohs(addr.sin_port) + 1);
    }

    // Close the socket
    close(sock);

    return 0;
}