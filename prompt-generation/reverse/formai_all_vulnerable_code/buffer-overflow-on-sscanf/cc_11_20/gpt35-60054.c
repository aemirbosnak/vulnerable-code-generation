//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
//This is a Simple HTTP Proxy example program, written in C
//It can be used to route HTTP requests from one server to another

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 4096
#define BACKLOG 5

int main(int argc, char *argv[]) {

    int listen_fd, conn_fd, remote_fd;
    struct sockaddr_in listen_addr, remote_addr, client_addr;
    char client_request[BUF_SIZE], remote_response[BUF_SIZE];
    ssize_t n;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <listen_port> <remote_host:remote_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Parse listen port number
    int listen_port = atoi(argv[1]);

    // Parse remote host and port number
    char remote_host[256];
    int remote_port;
    sscanf(argv[2], "%[^:]:%d", remote_host, &remote_port);

    // Create listening socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Bind socket to listen address
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(listen_port);
    if (bind(listen_fd, (struct sockaddr*) &listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("HTTP proxy started listening on port %d...\n", listen_port);

    // Handle incoming connections
    while (1) {
        
        // Accept incoming connection
        socklen_t client_addr_len = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr*) &client_addr, &client_addr_len);
        if (conn_fd == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pid_t pid = fork();

        if (pid == 0) {
           // Child process code: handle the request and send the response to the client

            // Connect to remote server
            char remote_port_str[16];
            sprintf(remote_port_str, "%d", remote_port);
            remote_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (remote_fd == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }
            memset(&remote_addr, 0, sizeof(remote_addr));
            remote_addr.sin_family = AF_INET;
            remote_addr.sin_port = htons(remote_port);
            if (inet_pton(AF_INET, remote_host, &remote_addr.sin_addr) != 1) {
                perror("inet_pton");
                exit(EXIT_FAILURE);
            }
            if (connect(remote_fd, (struct sockaddr*) &remote_addr, sizeof(remote_addr)) == -1) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            // Read request from the client
            memset(client_request, 0, BUF_SIZE);
            n = read(conn_fd, client_request, BUF_SIZE);
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

           // Forward the request to the remote server
            if (write(remote_fd, client_request, strlen(client_request)) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }

            // Read response from the remote server
            memset(remote_response, 0, BUF_SIZE);
            while ((n = read(remote_fd, remote_response, BUF_SIZE)) > 0) {
                
                // Forward the response to the client
                if (write(conn_fd, remote_response, n) == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
                memset(remote_response, 0, BUF_SIZE);
            }
            if (n == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Close sockets
            close(remote_fd);
            close(conn_fd);
            exit(EXIT_SUCCESS);

        } else if (pid > 0) {
            // Parent process code: continue listening for incoming connections
            close(conn_fd);
        } else {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }

    // Close socket
    close(listen_fd);
    return 0;
}