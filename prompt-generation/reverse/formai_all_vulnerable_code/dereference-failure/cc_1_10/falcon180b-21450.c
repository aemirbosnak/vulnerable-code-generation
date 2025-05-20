//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define BUFFER_SIZE 1024

void print_help(char* program_name) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", program_name);
}

int is_valid_port(int port) {
    return (port >= 1 && port <= MAX_PORT);
}

int create_socket() {
    int socket_fd;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    return socket_fd;
}

int connect_to_host(char* ip_address, int port) {
    struct sockaddr_in server_addr;
    int socket_fd;

    if ((socket_fd = create_socket()) == -1)
        return -1;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Invalid IP address\n");
        close(socket_fd);
        return -1;
    }

    if (connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to host: %s\n", strerror(errno));
        close(socket_fd);
        return -1;
    }

    return socket_fd;
}

int scan_port(int socket_fd, int port) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (send(socket_fd, " ", 1, 0) == -1) {
        printf("Error sending data: %s\n", strerror(errno));
        return -1;
    }

    bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("No response from port %d\n", port);
        return -1;
    } else {
        buffer[bytes_received] = '\0';
        printf("Port %d: %s\n", port, buffer);
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_help(argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_port(start_port) ||!is_valid_port(end_port)) {
        printf("Invalid port range\n");
        return 1;
    }

    for (int port = start_port; port <= end_port; port++) {
        int socket_fd = connect_to_host(ip_address, port);
        if (socket_fd == -1)
            continue;

        int result = scan_port(socket_fd, port);
        if (result == -1) {
            close(socket_fd);
            continue;
        }
    }

    return 0;
}