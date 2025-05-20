//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_BUF 1024

int main() {
    int listenfd, connfd, clientfd;
    struct sockaddr_in servaddr, clientaddr, client2addr;
    socklen_t len;
    char buf[MAX_BUF];

    // Create a listening socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the listening socket address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8080);

    // Bind the socket to the listening address
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(listenfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        // Accept an incoming connection
        len = sizeof(clientaddr);
        connfd = accept(listenfd, (struct sockaddr *)&clientaddr, &len);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        // Fork a new process to handle the client request
        if (fork() == 0) {
            // Close the listening socket in the child process
            close(listenfd);

            // Receive the HTTP request from the client
            int n;
            while ((n = recv(connfd, buf, MAX_BUF, 0)) > 0) {
                // Parse the HTTP request
                char *method = strtok(buf, " ");
                char *uri = strtok(NULL, " ");
                char *version = strtok(NULL, "\r\n");

                // Check if the method is GET
                if (strcmp(method, "GET") != 0) {
                    // Send an error response
                    char *error_response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
                    send(connfd, error_response, strlen(error_response), 0);
                } else {
                    // Connect to the destination server
                    clientfd = socket(AF_INET, SOCK_STREAM, 0);
                    if (clientfd < 0) {
                        perror("socket");
                        exit(1);
                    }

                    // Set up the destination server address
                    memset(&client2addr, 0, sizeof(client2addr));
                    client2addr.sin_family = AF_INET;
                    client2addr.sin_addr.s_addr = inet_addr("127.0.0.1");
                    client2addr.sin_port = htons(80);

                    // Connect to the destination server
                    if (connect(clientfd, (struct sockaddr *)&client2addr, sizeof(client2addr)) < 0) {
                        perror("connect");
                        exit(1);
                    }

                    // Send the HTTP request to the destination server
                    send(clientfd, buf, n, 0);

                    // Receive the HTTP response from the destination server
                    while ((n = recv(clientfd, buf, MAX_BUF, 0)) > 0) {
                        // Send the HTTP response to the client
                        send(connfd, buf, n, 0);
                    }

                    // Close the connection to the destination server
                    close(clientfd);
                }
            }

            // Close the connection to the client
            close(connfd);

            // Exit the child process
            exit(0);
        }

        // Close the connection to the client in the parent process
        close(connfd);
    }

    // Close the listening socket
    close(listenfd);

    return 0;
}