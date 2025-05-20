//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define SERVER_PORT 8080
#define PROXY_PORT 8888

int main(int argc, char* argv[]) {
    int server_fd, proxy_fd, client_fd, max_fd, valread;
    struct sockaddr_in server_addr, proxy_addr, client_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind server socket to port
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Create proxy socket
    if ((proxy_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set proxy address
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);

    // Bind proxy socket to port
    if (bind(proxy_fd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(proxy_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Print message that proxy server is ready
    printf("HTTP proxy server listening on port %d\n", PROXY_PORT);

    // Initialize set of file descriptors
    fd_set fds;

    while (1) {
        // Clear file descriptor set
        FD_ZERO(&fds);

        // Add server and proxy sockets to set
        FD_SET(server_fd, &fds);
        FD_SET(proxy_fd, &fds);

        // Find maximum file descriptor in set
        max_fd = (server_fd > proxy_fd) ? server_fd : proxy_fd;

        // Select ready file descriptors
        select(max_fd + 1, &fds, NULL, NULL, NULL);

        // Handle incoming client connections
        if (FD_ISSET(server_fd, &fds)) {
            int addr_len = sizeof(client_addr);

            // Accept client connection
            if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        // Handle incoming proxy connections
        if (FD_ISSET(proxy_fd, &fds)) {
            int addr_len = sizeof(client_addr);

            // Accept proxy connection
            if ((client_fd = accept(proxy_fd, (struct sockaddr*)&client_addr, (socklen_t*)&addr_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            printf("Accepted proxy connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        }

        // Read data from client and forward to server
        if (FD_ISSET(client_fd, &fds)) {
            if ((valread = read(client_fd, buffer, BUFFER_SIZE)) == 0) {
                // Client has closed connection
                close(client_fd);
                printf("Closed connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
            } else {
                // Connect to server
                if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
                    perror("socket failed");
                    exit(EXIT_FAILURE);
                }

                if (connect(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
                    perror("connect failed");
                    exit(EXIT_FAILURE);
                }

                // Forward data to server
                if (write(server_fd, buffer, valread) != valread) {
                    perror("write failed");
                    exit(EXIT_FAILURE);
                }

                memset(buffer, 0, BUFFER_SIZE);

                // Read response from server and forward to client
                if ((valread = read(server_fd, buffer, BUFFER_SIZE)) < 0) {
                    perror("read failed");
                    exit(EXIT_FAILURE);
                }

                if (write(client_fd, buffer, valread) != valread) {
                    perror("write failed");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }

    return 0;
}