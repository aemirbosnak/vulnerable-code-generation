//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: dynamic
/*
 * A simple C port scanner that uses a dynamic style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PORTS 1024

int main(int argc, char *argv[]) {
    // Check if the user provided a target host and port range
    if (argc != 3) {
        printf("Usage: %s <host> <port range>\n", argv[0]);
        return 1;
    }

    // Get the target host and port range from the command line arguments
    char *host = argv[1];
    char *port_range = argv[2];

    // Parse the port range into a start and end range
    int start_port = atoi(strtok(port_range, "-"));
    int end_port = atoi(strtok(NULL, "-"));

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Create a structure to store the target address
    struct sockaddr_in target_addr;
    target_addr.sin_family = AF_INET;
    target_addr.sin_port = htons(start_port);

    // Get the address of the target host
    struct hostent *host_info = gethostbyname(host);
    if (host_info == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Copy the target address into the target_addr structure
    memcpy(&target_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Loop through each port in the port range
    for (int port = start_port; port <= end_port; port++) {
        // Set the port number in the target_addr structure
        target_addr.sin_port = htons(port);

        // Connect to the target host and port
        if (connect(sock, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
            // If the connection was successful, print the open port number
            printf("Port %d is open\n", port);
        }
    }

    // Close the socket
    close(sock);

    return 0;
}