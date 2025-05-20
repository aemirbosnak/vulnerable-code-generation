//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    int port;
    char *ip;
    char buffer[BUF_SIZE];

    // Check for correct number of arguments
    if (argc!= 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    // Convert IP address from string to binary format
    ip = argv[1];
    inet_pton(AF_INET, ip, &server.sin_addr);

    // Set up socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address structure
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2])); // Start with first port

    // Loop through all ports
    for (port = atoi(argv[2]); port <= atoi(argv[3]); port++) {
        server.sin_port = htons(port); // Set port number

        // Connect to port and read any data
        if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
            memset(buffer, 0, BUF_SIZE);
            read(sock, buffer, BUF_SIZE);
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    // Close socket
    close(sock);

    return 0;
}