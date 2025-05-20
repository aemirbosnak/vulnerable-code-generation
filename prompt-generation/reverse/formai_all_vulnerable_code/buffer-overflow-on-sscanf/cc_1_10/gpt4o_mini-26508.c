//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8888
#define BUFFER_SIZE 4096

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) {
        perror("recv");
        close(client_socket);
        return;
    }

    buffer[bytes_read] = '\0';
    
    // Extract the URL from the request
    char method[10], url[256], protocol[10];
    sscanf(buffer, "%s %s %s", method, url, protocol);
    
    if (strcmp(method, "GET") != 0) {
        const char *response = "HTTP/1.1 501 Not Implemented\r\n\r\n";
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
        return;
    }

    // Parse the URL to get the host and path 
    char host[256];
    char path[256];
    char *pos = strstr(url, "//");
    if (pos) pos += 2; // Skip the "//"
    
    char *end = strchr(pos, '/');
    if (end) {
        strncpy(host, pos, end - pos);
        host[end - pos] = '\0';
        strcpy(path, end);
    } else {
        strcpy(host, pos);
        path[0] = '\0'; // Empty path
    }

    // Create a socket for the target host
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        close(client_socket);
        return;
    }

    struct hostent *server = gethostbyname(host);
    if (!server) {
        perror("gethostbyname");
        close(client_socket);
        return;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    // Connect to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(client_socket);
        close(server_socket);
        return;
    }

    // Forward the request to the target server
    char request[BUFFER_SIZE];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
    send(server_socket, request, strlen(request), 0);

    // Read the response from the target server and send it back to the client
    while ((bytes_read = recv(server_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    // Clean up
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces
    proxy_addr.sin_port = htons(PORT);

    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_socket, 5) < 0) {
        perror("listen");
        close(proxy_socket);
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy listening on port %d...\n", PORT);
    
    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        handle_request(client_socket);
    }

    close(proxy_socket);
    return 0;
}