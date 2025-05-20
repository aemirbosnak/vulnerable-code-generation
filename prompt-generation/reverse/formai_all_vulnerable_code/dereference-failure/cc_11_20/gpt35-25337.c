//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local_port> <remote_host:port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create local socket
    int local_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (local_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind local socket to specified port
    int local_port = atoi(argv[1]);
    struct sockaddr_in local_address;
    memset(&local_address, 0, sizeof(local_address));
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = htonl(INADDR_ANY);
    local_address.sin_port = htons(local_port);
    if (bind(local_socket, (struct sockaddr*) &local_address, sizeof(local_address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(local_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server started on port %d\n", local_port);

    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(local_socket, (struct sockaddr*) &client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Connect to remote host
        char* remote_host = strtok(argv[2], ":");
        char* remote_port = strtok(NULL, ":");
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }
        struct sockaddr_in remote_address;
        memset(&remote_address, 0, sizeof(remote_address));
        remote_address.sin_family = AF_INET;
        remote_address.sin_addr.s_addr = inet_addr(remote_host);
        remote_address.sin_port = htons(atoi(remote_port));
        if (connect(remote_socket, (struct sockaddr*) &remote_address, sizeof(remote_address)) < 0) {
            perror("connect");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // Forward data between local and remote sockets
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(client_socket, &read_fds);
        FD_SET(remote_socket, &read_fds);
        while (1) {
            fd_set tmp_read_fds = read_fds;
            if (select(FD_SETSIZE, &tmp_read_fds, NULL, NULL, NULL) < 0) {
                perror("select");
                break;
            }
            for (int i = 0; i < FD_SETSIZE; i++) {
                if (FD_ISSET(i, &tmp_read_fds)) {
                    char buffer[MAX_BUFFER_SIZE];
                    int num_bytes = read(i, buffer, MAX_BUFFER_SIZE);
                    if (num_bytes < 0) {
                        perror("read");
                        break;
                    } else if (num_bytes == 0) {
                        break;
                    }
                    int dst_socket = (i == client_socket) ? remote_socket : client_socket;
                    if (write(dst_socket, buffer, num_bytes) < 0) {
                        perror("write");
                        break;
                    }
                }
            }
        }

        close(client_socket);
        close(remote_socket);
    }

    return 0;
}