//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

void scan_port(const char *ip, int port) {
    int sock;
    struct sockaddr_in server;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sock == -1) {
        printf("Could not create socket\n");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    // Convert the IP address from text to binary
    if (inet_pton(AF_INET, ip, &server.sin_addr) <= 0) {
        printf("Invalid address: %s\n", ip);
        return;
    }

    // Attempt to connect to the target port
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        printf("Port %d: CLOSED\n", port);
    }

    close(sock); // Close the socket
    return;
}

int main(int argc, char *argv[]) {
    // To ensure the user provides enough arguments
    if (argc != 3) {
        printf("Usage: %s <IP> <port range (e.g., 1-1024)>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Basic variable declaration
    char *ip = argv[1];
    int start_port, end_port;

    // Splitting port range input into start and end values
    if (sscanf(argv[2], "%d-%d", &start_port, &end_port) != 2 || 
        start_port < 1 || end_port > 65535 || start_port > end_port) {
        printf("Invalid port range. Please use format 'start-end' with valid ports.\n");
        return EXIT_FAILURE;
    }

    // Loop through each port in the specified range
    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip, port); // Calling the scanning function
        usleep(100000); // Adding a slight delay to prevent overwhelming the target
    }

    return EXIT_SUCCESS;
}