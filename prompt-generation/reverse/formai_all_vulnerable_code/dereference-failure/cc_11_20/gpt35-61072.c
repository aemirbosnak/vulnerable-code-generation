//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <local port> <remote address> <remote port>\n", argv[0]);
        exit(1);
    }

    // Create local socket
    struct sockaddr_in local_addr;
    int local_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Configure local address
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(atoi(argv[1]));

    // Bind local socket to local address
    if (bind(local_socket, (struct sockaddr *)&local_addr, sizeof(local_addr)) != 0) {
        perror("Failed to bind local socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(local_socket, SOMAXCONN) != 0) {
        perror("Failed to listen for incoming connections");
        exit(1);
    }

    while (1) {
        // Accept incoming connection
        struct sockaddr_in remote_addr;
        socklen_t remote_addr_size = sizeof(remote_addr);
        int client_socket = accept(local_socket, (struct sockaddr *)&remote_addr, &remote_addr_size);

        if (client_socket < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        // Create remote socket
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);

        // Configure remote address
        struct hostent *remote_host = gethostbyname(argv[2]);
        if (!remote_host) {
            fprintf(stderr, "Failed to get remote host by name (%s)\n", argv[2]);
            continue;
        }
        char *remote_ip = inet_ntoa(*(struct in_addr *)remote_host->h_addr_list[0]);
        int remote_port = atoi(argv[3]);

        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(remote_ip);
        remote_addr.sin_port = htons(remote_port);

        // Connect to remote address
        if (connect(remote_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) != 0) {
            perror("Failed to connect to remote address");
            continue;
        }

        // Transfer data between sockets
        int ready_fd_count, max_fd;
        fd_set read_fds;
        char buffer[BUFFER_SIZE];

        while (1) {
            // Initialize the file descriptor set and set it to include both sockets
            FD_ZERO(&read_fds);
            FD_SET(client_socket, &read_fds);
            FD_SET(remote_socket, &read_fds);
            max_fd = (client_socket > remote_socket) ? client_socket : remote_socket;

            // Wait for activity on one of the file descriptors
            ready_fd_count = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
            if (ready_fd_count < 1) {
                perror("Failed to select file descriptor");
                break;
            }

            // Check which socket is ready
            if (FD_ISSET(client_socket, &read_fds)) {
                int read_count = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (read_count < 1) {
                    break;
                }
                send(remote_socket, buffer, read_count, 0);
            }
            if (FD_ISSET(remote_socket, &read_fds)) {
                int read_count = recv(remote_socket, buffer, BUFFER_SIZE, 0);
                if (read_count < 1) {
                    break;
                }
                send(client_socket, buffer, read_count, 0);
            }
        }

        close(client_socket);
        close(remote_socket);
    }

    close(local_socket);
    return 0;
}