//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_REQUEST_SIZE 4096

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a listening socket
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int reuseaddr = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address
    struct sockaddr_in listenaddr;
    memset(&listenaddr, 0, sizeof(listenaddr));
    listenaddr.sin_family = AF_INET;
    listenaddr.sin_addr.s_addr = inet_addr(argv[1]);
    listenaddr.sin_port = htons(atoi(argv[2]));
    if (bind(listenfd, (struct sockaddr *)&listenaddr, sizeof(listenaddr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(listenfd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Main loop
    while (1) {
        // Accept an incoming connection
        struct sockaddr_in clientaddr;
        socklen_t clientaddrlen = sizeof(clientaddr);
        int clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, &clientaddrlen);
        if (clientfd < 0) {
            perror("accept");
            continue;
        }

        // Fork a child process to handle the connection
        pid_t childpid = fork();
        if (childpid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (childpid == 0) {
            // Child process

            // Close the listening socket
            close(listenfd);

            // Read the request from the client
            char request[MAX_REQUEST_SIZE];
            memset(request, 0, sizeof(request));
            int bytes_read = read(clientfd, request, MAX_REQUEST_SIZE);
            if (bytes_read < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Parse the request
            char *method = strtok(request, " ");
            char *url = strtok(NULL, " ");
            char *version = strtok(NULL, "\r\n");

            // Check if the request is a GET request
            if (strcmp(method, "GET") != 0) {
                // Not a GET request
                char response[] = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
                write(clientfd, response, strlen(response));
                exit(EXIT_FAILURE);
            }

            // Parse the URL
            char *hostname = strtok(url, "/");
            char *path = strtok(NULL, "");

            // Resolve the hostname
            struct hostent *hostent = gethostbyname(hostname);
            if (hostent == NULL) {
                // Could not resolve the hostname
                char response[] = "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
                write(clientfd, response, strlen(response));
                exit(EXIT_FAILURE);
            }

            // Create a socket to connect to the server
            int serverfd = socket(AF_INET, SOCK_STREAM, 0);
            if (serverfd < 0) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            // Connect to the server
            struct sockaddr_in serveraddr;
            memset(&serveraddr, 0, sizeof(serveraddr));
            serveraddr.sin_family = AF_INET;
            serveraddr.sin_addr.s_addr = ((struct in_addr *)hostent->h_addr_list[0])->s_addr;
            serveraddr.sin_port = htons(80);
            if (connect(serverfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            // Send the request to the server
            write(serverfd, request, strlen(request));

            // Read the response from the server
            char response[MAX_REQUEST_SIZE];
            memset(response, 0, sizeof(response));
            int bytes_received = read(serverfd, response, MAX_REQUEST_SIZE);
            if (bytes_received < 0) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            // Send the response to the client
            write(clientfd, response, strlen(response));

            // Close the server socket
            close(serverfd);

            // Close the client socket
            close(clientfd);

            // Exit the child process
            exit(EXIT_SUCCESS);
        } else {
            // Parent process

            // Close the client socket
            close(clientfd);
        }
    }

    // Close the listening socket
    close(listenfd);

    return EXIT_SUCCESS;
}