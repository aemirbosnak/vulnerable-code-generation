//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

int main(int argc, char *argv[])
{
    char ip_address[16]; // For storing the IP address entered by user
    struct sockaddr_in target_addr; // sockaddr_in structure to store IP address and port number
    int open_ports[MAX_PORTS+1] = {0}; // Array to store open ports
    int scan_start, scan_end; // Variables to store start and end of port scan range
    int sockfd, conn_status;

    // Argument validation
    if (argc < 2) {
        printf("Usage: %s <IP Address> [Port-Range Start] [Port-Range End]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse IP address
    strcpy(ip_address, argv[1]);
    if (inet_pton(AF_INET, ip_address, &target_addr.sin_addr) < 0) {
        printf("Invalid IP address: %s\n", ip_address);
        exit(EXIT_FAILURE);
    }

    // Parse port range
    if (argc > 2) {
        scan_start = atoi(argv[2]);
        if (scan_start < 1 || scan_start > MAX_PORTS) {
            printf("Invalid port number: %d\n", scan_start);
            exit(EXIT_FAILURE);
        }
        if (argc > 3) {
            scan_end = atoi(argv[3]);
            if (scan_end < scan_start || scan_end > MAX_PORTS) {
                printf("Invalid port number: %d\n", scan_end);
                exit(EXIT_FAILURE);
            }
        } else {
            scan_end = MAX_PORTS;
        }
    } else {
        scan_start = 1;
        scan_end = MAX_PORTS;
    }

    // Loop through all ports in range
    for (int port = scan_start; port <= scan_end; port++) {
        
        // Create socket
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error creating socket");
            exit(EXIT_FAILURE);
        }

        // Set target address
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);

        // Connect to port
        conn_status = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        // Check if connection was successful
        if (conn_status == 0) {
            open_ports[port] = 1;
            printf("Port %d is open\n", port);
        } else {
            open_ports[port] = 0;
        }

        // Close socket
        close(sockfd);
    }

    // Print summary of results
    printf("\nPort scan completed for %s\n", ip_address);
    printf("Open ports: ");
    for (int port = scan_start; port <= scan_end; port++) {
        if (open_ports[port] == 1) {
            printf("%d,", port);
        }
    }

    return EXIT_SUCCESS;
}