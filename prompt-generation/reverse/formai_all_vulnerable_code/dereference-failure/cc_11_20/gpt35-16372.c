//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUF_SIZE 4096

int main(int argc, char* argv[]) {

    if (argc != 3) {
        printf("Usage: %s <port_number> <webserver_hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port_number = atoi(argv[1]);
    char* webserver_hostname = argv[2];

    // Create a socket for the proxy
    int proxy_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket_fd == -1) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(port_number);
    if (bind(proxy_socket_fd, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) == -1) {
        perror("Error binding socket");
        exit(EXIT_FAILURE);
    }

    // Listen for connections on the socket
    if (listen(proxy_socket_fd, 10) == -1) {
        perror("Error listening on socket");
        exit(EXIT_FAILURE);
    }

    // Main loop to handle incoming connections
    while (1) {

        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_socket_fd = accept(proxy_socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket_fd == -1) {
            perror("Error accepting connection");
            continue; // Skip current iteration and move to next iteration of loop
        }

        // Fork a child process to handle the request
        int pid = fork();
        if (pid == -1) {
            perror("Error forking process");
            continue; // Skip current iteration and move to next iteration of loop
        } else if (pid == 0) {
            // Child process
            close(proxy_socket_fd);

            // Extract the request from the client socket
            char request[BUF_SIZE];
            int read_size = recv(client_socket_fd, request, BUF_SIZE, 0);
            if (read_size == -1) {
                perror("Error receiving request from client");
                exit(EXIT_FAILURE);
            }

            // Extract the destination hostname and port from the request
            char *host = strtok(request, " ");
            host = strtok(NULL, " ");
            host = strtok(host + 2, "/");
            char *port = strtok(host, ":");
            host = strtok(NULL, ":");

            // Create a socket for the destination server
            int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_socket_fd == -1) {
                perror("Error opening socket");
                exit(EXIT_FAILURE);
            }

            // Resolve the destination IP address
            struct hostent *server_hostent = gethostbyname(host);
            if (!server_hostent) {
                fprintf(stderr, "Error resolving hostname: %s\n", host);
                exit(EXIT_FAILURE);
            }

            // Connect to the destination server
            struct sockaddr_in server_addr;
            memset(&server_addr, 0, sizeof(server_addr));
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(atoi(port));
            memcpy(&server_addr.sin_addr.s_addr, server_hostent->h_addr, server_hostent->h_length);
            if (connect(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
                perror("Error connecting to server");
                exit(EXIT_FAILURE);
            }

            // Forward the request to the destination server
            if (send(server_socket_fd, request, read_size, 0) == -1) {
                perror("Error sending request to server");
                exit(EXIT_FAILURE);
            }

            // Read the response from the destination server
            char response[BUF_SIZE];
            read_size = recv(server_socket_fd, response, BUF_SIZE, 0);
            if (read_size == -1) {
                perror("Error receiving response from server");
                exit(EXIT_FAILURE);
            }

            // Forward the response to the client socket
            if (send(client_socket_fd, response, read_size, 0) == -1) {
                perror("Error sending response to client");
                exit(EXIT_FAILURE);
            }

            // Close both sockets and exit the child process
            close(server_socket_fd);
            close(client_socket_fd);
            exit(EXIT_SUCCESS);

        } else {
            // Parent process
            close(client_socket_fd);
            wait(NULL);
        }

    }

    return 0;
}