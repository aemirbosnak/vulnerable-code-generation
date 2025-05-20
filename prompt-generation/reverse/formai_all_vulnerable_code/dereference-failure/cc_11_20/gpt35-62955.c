//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <listen port> <destination IP> <destination port>\n", argv[0]);
        return 1;
    }

    // Parse command line arguments
    char* local_port_str = argv[1];
    char* remote_ip = argv[2];
    char* remote_port_str = argv[3];
    int local_port = atoi(local_port_str);
    int remote_port = atoi(remote_port_str);

    // Create socket and listen on specified port
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return errno;
    }

    struct sockaddr_in local_addr = {
        .sin_family = AF_INET, 
        .sin_addr.s_addr = htonl(INADDR_ANY), 
        .sin_port = htons(local_port)    
    };

    if (bind(listen_fd, (struct sockaddr*)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind");
        close(listen_fd);
        return errno;
    }

    if (listen(listen_fd, SOMAXCONN) == -1) {
        perror("listen");
        close(listen_fd);
        return errno;
    }

    printf("Proxy listening on port %d...\n", local_port);

    // Main loop
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr = {0};
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &client_addr_len);

        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        printf("Accepted new connection...\n");

        // Create new socket and connect to remote host
        int remote_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (remote_fd == -1) {
            perror("socket");
            close(client_fd);
            continue;
        }

        struct sockaddr_in remote_addr = {
            .sin_family = AF_INET, 
            .sin_addr.s_addr = inet_addr(remote_ip), 
            .sin_port = htons(remote_port)    
        };

        if (connect(remote_fd, (struct sockaddr*)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_fd);
            close(remote_fd);
            continue;
        }

        printf("Connected to remote host %s:%d...\n", remote_ip, remote_port);

        // Forward data between sockets
        char buf[BUFFER_SIZE];
        ssize_t bytes_read = 0;

        while ((bytes_read = recv(client_fd, buf, BUFFER_SIZE, 0)) > 0) {
            send(remote_fd, buf, bytes_read, 0);
        }

        if (bytes_read == -1) {
            perror("recv");
        }

        close(client_fd);
        close(remote_fd);
    }

    close(listen_fd);
    return 0;
}