//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

// Function to check if a port is open
int isPortOpen(char *ip, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return 0;
    }

    // Close the socket
    close(sockfd);

    // Return 1 if the port is open, 0 otherwise
    return 1;
}

// Function to scan a range of ports on a given IP address
void portScan(char *ip, int startPort, int endPort) {
    int port;

    // Iterate over the range of ports
    for (port = startPort; port <= endPort; port++) {
        // Check if the port is open
        if (isPortOpen(ip, port)) {
            printf("Port %d is open\n", port);
        }
    }
}

int main() {
    // Get the IP address of the host to scan
    char ip[16];
    printf("Enter the IP address of the host to scan: ");
    scanf("%s", ip);

    // Get the starting and ending ports to scan
    int startPort, endPort;
    printf("Enter the starting port to scan: ");
    scanf("%d", &startPort);
    printf("Enter the ending port to scan: ");
    scanf("%d", &endPort);

    // Scan the range of ports
    portScan(ip, startPort, endPort);

    return 0;
}