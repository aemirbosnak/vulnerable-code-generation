//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: decentralized
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define PORT_SCAN_DELAY 0.05

int main() {

    // Define the target host and port range
    char host[256];
    int port_start, port_end;
    printf("Enter target host: ");
    scanf("%s", host);
    printf("Enter port start: ");
    scanf("%d", &port_start);
    printf("Enter port end: ");
    scanf("%d", &port_end);

    // Allocate memory for the port scan results
    int results[port_end - port_start + 1];
    memset(results, 0, (port_end - port_start + 1) * sizeof(int));

    // Perform the port scan
    for (int port = port_start; port <= port_end; port++) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        // Connect to the socket
        struct sockaddr_in server_addr;
        server_addr.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            // Port is open, set the result
            results[port - port_start] = 1;
        }

        // Close the socket
        close(sockfd);

        // Sleep for the delay
        sleep(PORT_SCAN_DELAY);
    }

    // Print the results
    printf("Port scan results:\n");
    for (int i = 0; i < port_end - port_start + 1; i++) {
        if (results[i] == 1) {
            printf("Port %d is open.\n", port_start + i);
        }
    }

    return 0;
}