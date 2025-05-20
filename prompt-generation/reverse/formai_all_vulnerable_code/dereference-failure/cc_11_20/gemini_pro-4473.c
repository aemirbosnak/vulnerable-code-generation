//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local_port> <remote_host:port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the local port number and remote host:port
    int local_port = atoi(argv[1]);
    char *remote_host_port = argv[2];

    // Create a socket for the local proxy server
    int local_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (local_socket == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the local address and port for the proxy server
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(local_port);

    // Bind the local socket to the address and port
    if (bind(local_socket, (struct sockaddr *)&local_addr, sizeof(local_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections on the local socket
    if (listen(local_socket, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (1) {
        // Accept an incoming connection from a client
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket = accept(local_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        // Extract the remote host and port from the remote_host_port string
        char *remote_host = strtok(remote_host_port, ":");
        char *remote_port = strtok(NULL, ":");

        // Create a socket for the connection to the remote server
        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket == -1) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Set up the remote address and port for the connection to the remote server
        struct sockaddr_in remote_addr;
        memset(&remote_addr, 0, sizeof(remote_addr));
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(remote_host);
        remote_addr.sin_port = htons(atoi(remote_port));

        // Connect to the remote server
        if (connect(remote_socket, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
            perror("connect");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // Fork a new process to handle the client request
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        // In the child process, relay data between the client and remote server
        if (pid == 0) {
            char buffer[MAX_BUFFER_SIZE];
            int bytes_read;

            // Relay data from the client to the remote server
            while ((bytes_read = read(client_socket, buffer, sizeof(buffer))) > 0) {
                if (write(remote_socket, buffer, bytes_read) == -1) {
                    perror("write");
                    break;
                }
            }

            // Relay data from the remote server to the client
            while ((bytes_read = read(remote_socket, buffer, sizeof(buffer))) > 0) {
                if (write(client_socket, buffer, bytes_read) == -1) {
                    perror("write");
                    break;
                }
            }

            // Close the sockets and exit the child process
            close(client_socket);
            close(remote_socket);
            exit(EXIT_SUCCESS);
        }

        // In the parent process, close the client socket and continue listening for new connections
        close(client_socket);
    }

    // Close the local socket and exit the main process
    close(local_socket);
    return EXIT_SUCCESS;
}