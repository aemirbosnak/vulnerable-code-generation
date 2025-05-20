//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    // Create a socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return -1;
    }

    // Set up the socket address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the address
    int bind_result = bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (bind_result < 0) {
        perror("bind");
        return -1;
    }

    // Listen for connections
    int listen_result = listen(server_fd, 5);
    if (listen_result < 0) {
        perror("listen");
        return -1;
    }

    // Accept connections
    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        // Handle the connection
        char buffer[4096];
        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_received < 0) {
            perror("recv");
            close(client_fd);
            continue;
        }

        // Parse the request
        char *request_line = strtok(buffer, "\r\n");
        char *method = strtok(request_line, " ");
        char *path = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        // Send the response
        if (strcmp(method, "GET") == 0) {
            if (strcmp(path, "/") == 0) {
                // Send the index page
                char *index_page = "<h1>Welcome to the Future of Web Servers!</h1>";
                int content_length = strlen(index_page);
                char *response = malloc(1024);
                sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n%s", content_length, index_page);
                int bytes_sent = send(client_fd, response, strlen(response), 0);
                if (bytes_sent < 0) {
                    perror("send");
                    close(client_fd);
                    continue;
                }
            } else {
                // Send a 404 error
                char *error_page = "<h1>404 Not Found</h1>";
                int content_length = strlen(error_page);
                char *response = malloc(1024);
                sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n%s", content_length, error_page);
                int bytes_sent = send(client_fd, response, strlen(response), 0);
                if (bytes_sent < 0) {
                    perror("send");
                    close(client_fd);
                    continue;
                }
            }
        } else {
            // Send a 405 error
            char *error_page = "<h1>405 Method Not Allowed</h1>";
            int content_length = strlen(error_page);
            char *response = malloc(1024);
            sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: %d\r\n\r\n%s", content_length, error_page);
            int bytes_sent = send(client_fd, response, strlen(response), 0);
            if (bytes_sent < 0) {
                perror("send");
                close(client_fd);
                continue;
            }
        }

        // Close the connection
        close(client_fd);
    }

    // Close the socket
    close(server_fd);

    return 0;
}