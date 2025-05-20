//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 6666
#define BUFFER_SIZE 512

int main() {
    int server_fd, client_fd, optval = 1;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[BUFFER_SIZE];
    int n;

    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    // Set the server socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind the server socket to the server address
    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept incoming connections
        client_addr_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        // Receive data from the client
        n = recv(client_fd, buffer, BUFFER_SIZE, 0);
        if (n == -1) {
            perror("recv");
            close(client_fd);
            continue;
        }

        // Process the data from the client
        buffer[n] = '\0';
        printf("Received from client: %s\n", buffer);

        // Send data to the client
        n = send(client_fd, buffer, strlen(buffer), 0);
        if (n == -1) {
            perror("send");
            close(client_fd);
            continue;
        }

        // Close the client socket
        close(client_fd);
    }

    // Close the server socket
    close(server_fd);

    return 0;
}