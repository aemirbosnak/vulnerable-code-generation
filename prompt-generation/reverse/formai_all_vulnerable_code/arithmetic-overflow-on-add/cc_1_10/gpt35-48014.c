//FormAI DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    printf("Hello there! Let's start scanning ports, shall we?\n");

    // Check if IP address is provided
    if (argc < 2) {
        printf("Oops! You forgot to enter the IP address. Please try again.\n");
        return 1;
    }

    char *ip = argv[1]; // Get IP address from command line argument
    int start_port, end_port;

    printf("\nWe will now scan the ports on %s.\n", ip);

    // Get start and end port from user
    printf("Please enter the starting port: ");
    scanf("%d", &start_port);
    printf("Please enter the ending port: ");
    scanf("%d", &end_port);

    // Create a socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket. Please try again.\n");
        return 1;
    }

    // Scan ports
    for (int port = start_port; port <= end_port; port++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(ip);
        addr.sin_port = htons(port);

        // Try to connect to a port
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
            printf("Port %d is closed.\n", port);
        } else {
            printf("Port %d is open!\n", port);
            // Close the port after scanning
            close(sock);
            // Re-create the socket
            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                printf("Failed to create socket. Please try again.\n");
                return 1;
            }
        }
    }

    printf("\nThat was fun! I hope you found what you were looking for. See you next time!\n");

    return 0;
}