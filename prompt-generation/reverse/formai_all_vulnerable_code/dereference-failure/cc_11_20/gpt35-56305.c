//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 4096
#define NUM_CONNECTIONS 10

int main(int argc, char *argv[]) {
    // Check if user entered the correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <server_ip>\n", argv[0]);
        return 1;
    }

    // Convert port number from string to integer
    int port = atoi(argv[1]);

    // Get server address from input
    struct hostent *server = gethostbyname(argv[2]);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", argv[2]);
        return 1;
    }

    // Create socket for listening for incoming connections
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Set socket options to allow reuse of address and port
    int reuse = 1;
    if (setsockopt(listen_sock, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse)) < 0) {
        perror("Error setting SO_REUSEADDR option");
        return 1;
    }

    // Bind socket to local address and port
    struct sockaddr_in local_addr;
    memset(&local_addr, 0, sizeof(local_addr));
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(port);
    if (bind(listen_sock, (struct sockaddr*)&local_addr, sizeof(local_addr)) < 0) {
        perror("Error binding socket");
        return 1;
    }

    // Listen for incoming connections
    if (listen(listen_sock, NUM_CONNECTIONS) < 0) {
        perror("Error listening for connections");
        return 1;
    }

    printf("Proxy listening on port %d...\n", port);

    // Loop to handle client requests
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock < 0) {
            perror("Error accepting connection");
            continue;
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Read client request
        char buf[MAX_BUF_SIZE];
        ssize_t bytes_read = read(client_sock, buf, MAX_BUF_SIZE);
        if (bytes_read < 0) {
            perror("Error reading request");
            close(client_sock);
            continue;
        }

        printf("Received request from client:\n%s\n", buf);

        // Create socket for connection to remote server
        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock < 0) {
            perror("Error creating socket");
            close(client_sock);
            continue;
        }

        // Connect to remote server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = ((struct in_addr*)(server->h_addr))->s_addr;
        server_addr.sin_port = htons(80);
        if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Error connecting to server");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Connected to remote server\n");

        // Write client request to remote server
        if (write(server_sock, buf, bytes_read) < 0) {
            perror("Error writing request to server");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Sent request to server:\n%s\n", buf);

        // Read response from remote server
        bytes_read = read(server_sock, buf, MAX_BUF_SIZE);
        if (bytes_read < 0) {
            perror("Error reading response from server");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Received response from server:\n%s\n", buf);

        // Write response to client
        if (write(client_sock, buf, bytes_read) < 0) {
            perror("Error writing response to client");
            close(client_sock);
            close(server_sock);
            continue;
        }

        printf("Sent response to client:\n%s\n", buf);

        // Close client and server sockets
        close(client_sock);
        close(server_sock);
    }

    return 0;
}