//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_error(const char* message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);

    // Create socket
    int socket_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd == -1) {
        print_error("socket");
    }

    // Set socket options
    int opt = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        print_error("setsockopt");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char buffer[BUFFER_SIZE];
    while (1) {
        // Receive data from server
        int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            print_error("recv");
            break;
        }

        // Print received data
        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }

    // Close socket
    close(socket_fd);

    return 0;
}