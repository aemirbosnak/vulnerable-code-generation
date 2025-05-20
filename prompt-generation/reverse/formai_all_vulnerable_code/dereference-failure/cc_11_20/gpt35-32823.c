//FormAI DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 0;
    }

    // Store IP address and port range
    char *ip_address = argv[1]; 
    char *port_range = argv[2]; 

    // Split port range into start and end ports
    char *port_start_str = strtok(port_range, "-");
    char *port_end_str = strtok(NULL, "-");

    // Store start and end ports as integers
    int port_start = atoi(port_start_str);
    int port_end = atoi(port_end_str);

    // Validate input values
    if (port_start <= 0 || port_end <= 0 || port_end < port_start) {
        printf("Invalid port range!\n");
        return 0;
    }

    // Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set socket timeout (1 second)
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);

    // Prepare server address struct
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port_start);

    // Scan ports within the range
    for (int port = port_start; port <= port_end; port++) {
        // Set server address port number
        server_address.sin_port = htons(port);

        // Convert IP address to binary format
        if (inet_pton(AF_INET, ip_address, &server_address.sin_addr) <= 0) {
            printf("Invalid IP address!\n");
            return 0;
        }

        // Attempt to connect to the server
        if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            if (errno == ECONNREFUSED) {
                // Port is closed
                printf("Port %d is closed\n", port);
                close(sockfd);
                continue;
            }
            else if (errno == EINTR || errno == EAGAIN || errno == EWOULDBLOCK) {
                // Timeout occurred or connection was interrupted
                printf("Port %d timed out or connection interrupted\n", port);
                close(sockfd);
                break;
            }
            else {
                // Unknown error occurred
                printf("Error: %s\n", strerror(errno));
                close(sockfd);
                break;
            }
        }

        // Connection successful, port is open
        printf("Port %d is open\n", port);
        close(sockfd);
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof timeout);
    }

    return 0;
}