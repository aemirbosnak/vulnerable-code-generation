//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

// Function to check if a port is open or not
void check_port(int sockfd, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == 0) {
        printf("Port %d is open.\n", port);
    } else {
        printf("Port %d is closed.\n", port);
    }
}

int main() {
    int sockfd, result;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    printf("Enter the IP address: ");
    scanf("%s", buffer);

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, buffer, &server_addr.sin_addr);

    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result == -1) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    printf("Enter the range of ports to scan (e.g. 1-100): ");
    scanf("%s", buffer);

    // Parse the range of ports
    int start_port, end_port;
    sscanf(buffer, "%d-%d", &start_port, &end_port);

    // Check if the range is valid
    if (start_port > end_port || start_port < 1 || end_port > MAX_PORTS) {
        printf("Invalid port range.\n");
        exit(1);
    }

    // Check each port in the range
    for (int i = start_port; i <= end_port; i++) {
        check_port(sockfd, i);
    }

    close(sockfd);
    return 0;
}