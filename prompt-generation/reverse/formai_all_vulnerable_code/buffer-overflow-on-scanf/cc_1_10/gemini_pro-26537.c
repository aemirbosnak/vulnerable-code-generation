//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT_NUMBER 65535

int main() {
    // Initialize the socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the target IP address.
    char target_ip[INET_ADDRSTRLEN];
    printf("Enter the target IP address: ");
    scanf("%s", target_ip);

    // Convert the target IP address to a binary format.
    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    if (inet_pton(AF_INET, target_ip, &target_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Scan the ports.
    for (int port = 1; port <= MAX_PORT_NUMBER; port++) {
        // Set the target port.
        target_addr.sin_port = htons(port);

        // Connect to the target port.
        int ret = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        // Check if the connection was successful.
        if (ret == 0) {
            printf("Port %d is open!\n", port);
        }
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}