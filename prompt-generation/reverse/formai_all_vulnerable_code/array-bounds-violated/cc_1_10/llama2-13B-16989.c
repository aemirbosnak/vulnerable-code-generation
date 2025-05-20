//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 10000  // Range of ports to scan (10000-65535)
#define HOST_ADDRESS "192.168.1.100" // Target host IP address
#define MAX_CLIENTS 50      // Maximum number of clients to scan simultaneously

struct client_info {
    int sock;    // Socket descriptor
    int port;   // Port number
};

int main(int argc, char *argv[]) {
    int sock = 0; // Socket descriptor
    int port = 0; // Port number
    struct client_info clients[MAX_CLIENTS]; // Array to store client information
    int i = 0; // Iterator for clients

    // Initialize sockets
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up target host IP address and port range
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // Listen on port 80
    inet_pton(AF_INET, HOST_ADDRESS, &server_addr.sin_addr);

    // Connect to target host
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connect failed");
        exit(EXIT_FAILURE);
    }

    // Initialize client information array
    for (i = 0; i < MAX_CLIENTS; i++) {
        clients[i].sock = -1;
        clients[i].port = 0;
    }

    // Start scanning for open ports
    for (port = 10000; port < 65535; port++) {
        // Create a new socket for each client
        clients[i].sock = socket(AF_INET, SOCK_STREAM, 0);
        if (clients[i].sock < 0) {
            perror("Socket creation failed");
            exit(EXIT_FAILURE);
        }

        // Connect to target host on the current port
        if (connect(clients[i].sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Connect failed");
            close(clients[i].sock);
            clients[i].sock = -1;
            continue;
        }

        // Get the current port number
        clients[i].port = ntohs(getsockport(clients[i].sock));

        // Print the open port
        printf("Port %d is open\n", clients[i].port);

        // Close the socket and move to the next port
        close(clients[i].sock);
        clients[i].sock = -1;
    }

    // Clean up and exit
    close(sock);
    return 0;
}

// Get the socket port number from a socket descriptor
int getsockport(int sock) {
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    getpeername(sock, (struct sockaddr *)&client_addr, &client_len);
    return ntohs(client_addr.sin_port);
}