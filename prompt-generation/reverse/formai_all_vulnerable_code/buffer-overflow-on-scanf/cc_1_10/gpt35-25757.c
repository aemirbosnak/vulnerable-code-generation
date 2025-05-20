//FormAI DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void portScanner(char *ip, int startPort, int endPort) {
    int sd;
    struct sockaddr_in target;
    int portsOpen = 0;

    // Create socket descriptor
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd == -1) {
        perror("socket");
        exit(1);
    }

    // Set properties for sockaddr_in struct
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(ip);

    // Loop through all port numbers to be scanned
    for (int port = startPort; port <= endPort; port++) {
        // Set port number for sockaddr_in struct
        target.sin_port = htons(port);

        // Attempt to connect to port
        if (connect(sd, (struct sockaddr *) &target, sizeof(target)) == 0) {
            printf("Port %d is open\n", port);
            portsOpen++;
        }
    }

    // Close socket descriptor
    close(sd);

    printf("Scan completed: %d ports open\n", portsOpen);
}

int main() {
    char ip[16];
    int startPort, endPort;

    // Get input values from user
    printf("Enter IP address to scan: ");
    scanf("%15s", ip);

    printf("Enter start port number: ");
    scanf("%d", &startPort);

    printf("Enter end port number: ");
    scanf("%d", &endPort);

    if (startPort < 1 || endPort > 65535) {
        printf("Invalid port number input\n");
        return 1;
    }

    // Call portScanner function with user input values
    portScanner(ip, startPort, endPort);

    return 0;
}