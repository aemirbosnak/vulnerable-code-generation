//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port, end_port;

    // Parse port range
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    // Initialize socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Loop through ports
    for (int port = start_port; port <= end_port; port++) {
        // Set server address for current port
        server_addr.sin_port = htons(port);

        // Connect to port
        if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        // Receive data from server (if any)
        bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Received data: %s", buffer);
        }
    }

    // Close socket
    close(socket_fd);

    return 0;
}