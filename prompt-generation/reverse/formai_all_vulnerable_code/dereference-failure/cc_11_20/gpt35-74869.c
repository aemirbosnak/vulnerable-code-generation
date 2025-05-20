//FormAI DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc != 3)
    {
        printf("Usage: %s <IP address> <Port range>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the IP address
    struct in_addr ip_addr;
    if (inet_pton(AF_INET, argv[1], &ip_addr) != 1)
    {
        printf("Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Parse the port range
    int start_port, end_port;
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2)
    {
        printf("Invalid port range: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Check that the port range is valid
    if (start_port < 1 || start_port > 65535 || end_port < 1 || end_port > 65535 || start_port > end_port)
    {
        printf("Invalid port range: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Failed to create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Set the socket options to reuse the address
    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) != 0)
    {
        printf("Failed to set socket options: %s\n", strerror(errno));
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Loop through the ports and try to connect to each one
    struct sockaddr_in target_addr = {0};
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr = ip_addr;
    int port;
    for (port = start_port; port <= end_port; ++port)
    {
        target_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0)
        {
            printf("Port %d is open.\n", port);
        }
        else
        {
            printf("Port %d is closed.\n", port);
        }
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}