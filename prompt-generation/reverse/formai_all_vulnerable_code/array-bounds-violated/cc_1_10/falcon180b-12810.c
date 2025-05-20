//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void print_usage(const char* program_name) {
    fprintf(stdout, "Usage: %s <IP address> <port number>\n", program_name);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);
    int socket_fd;
    struct sockaddr_in server_addr;

    // Create socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(port_number);

    // Connect to server
    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        close(socket_fd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Receive data from server
    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(socket_fd);
    return 0;
}