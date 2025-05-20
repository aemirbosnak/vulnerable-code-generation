//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: introspective
/*
 * C Port Scanner Example Program
 *
 * Author: [Your Name]
 * Date:   [Today's Date]
 *
 * Description: This program uses the `socket()` and `connect()` functions
 *              to scan a given IP address and port range for open ports.
 *
 * Usage:
 *    ./port_scanner <ip_address> <port_range_start> <port_range_end>
 *
 * Example:
 *    ./port_scanner 127.0.0.1 22 25
 *
 * Output:
 *    Port 22 is open
 *    Port 25 is closed
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    // Check for correct number of arguments
    if (argc != 4) {
        printf("Usage: ./port_scanner <ip_address> <port_range_start> <port_range_end>\n");
        return 1;
    }

    // Get the IP address and port range from the command line arguments
    char *ip_address = argv[1];
    int port_range_start = atoi(argv[2]);
    int port_range_end = atoi(argv[3]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Initialize the socket address struct
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_range_start);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    // Loop through the port range and check for open ports
    for (int port = port_range_start; port <= port_range_end; port++) {
        server_addr.sin_port = htons(port);

        // Attempt to connect to the server
        if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}