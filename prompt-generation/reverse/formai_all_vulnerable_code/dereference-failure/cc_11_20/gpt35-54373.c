//FormAI DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Check if user has inputted valid arguments
    if (argc != 4) {
        printf("Usage: %s <IP Address> <start port> <end port>\n", argv[0]);
        exit(1);
    }
    
    // Parse IP address string into binary form
    struct sockaddr_in sa;
    int result = inet_pton(AF_INET, argv[1], &(sa.sin_addr));
    if (result == 0) {
        printf("Invalid IP address\n");
        exit(1);
    } else if (result == -1) {
        perror("Error in inet_pton");
        exit(1);
    }
    
    // Parse start and end port strings into integers
    char *ptr;
    long start_port = strtol(argv[2], &ptr, 10);
    if (*ptr != '\0' || start_port < 0 || start_port > 65535) {
        printf("Invalid start port\n");
        exit(1);
    }
    long end_port = strtol(argv[3], &ptr, 10);
    if (*ptr != '\0' || end_port < 0 || end_port > 65535) {
        printf("Invalid end port\n");
        exit(1);
    }
    
    // Initialize random number generator
    srand(time(NULL));
    
    // Begin scanning ports
    printf("Starting port scan of %s from %ld to %ld\n", argv[1], start_port, end_port);
    for (int port = start_port; port <= end_port; port++) {
        // Create socket
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("Error creating socket");
            exit(1);
        }
        
        // Set socket options
        int optval = 1;
        setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));
        
        // Create sockaddr_in struct for remote host
        struct sockaddr_in remote;
        remote.sin_family = AF_INET;
        remote.sin_addr = sa.sin_addr;
        remote.sin_port = htons(port);
        
        // Connect to remote host
        int result = connect(sock, (struct sockaddr *)&remote, sizeof(remote));
        if (result == 0) {
            printf("Port %d open\n", port);
        } else {
            if (rand() % 2 == 0) {
                printf("Port %d closed\n", port);
            }
        }
        
        // Close socket
        close(sock);
    }
    
    printf("Port scan complete\n");
    
    return 0;
}