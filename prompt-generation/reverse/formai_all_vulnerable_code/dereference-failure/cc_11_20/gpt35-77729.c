//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PROXY_PORT 8888

int main(int argc, char *argv[]) {
    int proxy_fd, client_fd, server_fd, max_fd;
    struct sockaddr_in proxy_addr, client_addr, server_addr;
    char request_buffer[BUFFER_SIZE], response_buffer[BUFFER_SIZE];
    fd_set readfds;

    // create proxy socket
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PROXY_PORT);
    proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_fd < 0) {
        perror("Could not create proxy socket");
        exit(EXIT_FAILURE);
    }
    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Could not bind proxy socket");
        exit(EXIT_FAILURE);
    }
    if (listen(proxy_fd, 10) < 0) {
        perror("Could not listen on proxy socket");
        exit(EXIT_FAILURE);
    }

    // main proxy loop
    while (true) {
        // set up file descriptor set for select
        FD_ZERO(&readfds);
        FD_SET(proxy_fd, &readfds);
        max_fd = proxy_fd;
        // check for incoming connections
        if (select(max_fd + 1, &readfds, NULL, NULL, NULL) < 0) {
            perror("Could not select");
            exit(EXIT_FAILURE);
        }
        if (FD_ISSET(proxy_fd, &readfds)) {
            socklen_t client_addr_len = sizeof(client_addr);
            client_fd = accept(proxy_fd, (struct sockaddr *) &client_addr, &client_addr_len);
            if (client_fd < 0) {
                perror("Could not accept client connection");
                continue;
            }
            // read request from client
            memset(request_buffer, 0, BUFFER_SIZE);
            int bytes_read = read(client_fd, request_buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("Could not read client request");
                close(client_fd);
                continue;
            }
            // parse hostname from request
            char *hostname_start = strstr(request_buffer, "Host: ") + 6;
            char *hostname_end = strchr(hostname_start, '\r');
            if (!hostname_end) {
                perror("Invalid client request");
                close(client_fd);
                continue;
            }
            char hostname[BUFFER_SIZE];
            strncpy(hostname, hostname_start, hostname_end - hostname_start);
            hostname[hostname_end - hostname_start] = '\0';
            // connect to server
            memset(&server_addr, 0, sizeof(server_addr));
            struct hostent *server = gethostbyname(hostname);
            if (!server) {
                perror("Could not resolve server hostname");
                close(client_fd);
                continue;
            }
            memcpy(&server_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(80);
            server_fd = socket(AF_INET, SOCK_STREAM, 0);
            if (server_fd < 0) {
                perror("Could not create server socket");
                close(client_fd);
                continue;
            }
            if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
                perror("Could not connect to server");
                close(client_fd);
                close(server_fd);
                continue;
            }
            // send request to server
            if (write(server_fd, request_buffer, bytes_read) < 0) {
                perror("Could not send request to server");
                close(client_fd);
                close(server_fd);
                continue;
            }
            // read response from server
            memset(response_buffer, 0, BUFFER_SIZE);
            bytes_read = read(server_fd, response_buffer, BUFFER_SIZE);
            if (bytes_read < 0) {
                perror("Could not read response from server");
                close(client_fd);
                close(server_fd);
                continue;
            }
            // send response to client
            if (write(client_fd, response_buffer, bytes_read) < 0) {
                perror("Could not send response to client");
                close(client_fd);
                close(server_fd);
                continue;
            }
            // close sockets and move on to next request
            close(client_fd);
            close(server_fd);
        }
    }
    return 0;
}