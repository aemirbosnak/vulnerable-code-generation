//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        // Read from server
        int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received from server: %s\n", buffer);

        // Send to server
        if (send(socket_fd, buffer, strlen(buffer), 0) == -1) {
            fprintf(stderr, "Error sending to server: %s\n", strerror(errno));
            exit(1);
        }
    }

    // Close socket
    if (close(socket_fd) == -1) {
        fprintf(stderr, "Error closing socket: %s\n", strerror(errno));
        exit(1);
    }

    return 0;
}