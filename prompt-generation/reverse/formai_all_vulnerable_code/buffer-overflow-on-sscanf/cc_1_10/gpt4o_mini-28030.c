//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define MAX_BUFFER 8192
#define PORT 8080

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void handle_client(int client_socket) {
    char buffer[MAX_BUFFER];
    char method[10], url[100], protocol[10];
    char *hostname, *port_str;
    int port = 80;

    memset(buffer, 0, sizeof(buffer));
    int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        error("Error receiving data");
    }

    // Analyzing the HTTP request
    sscanf(buffer, "%s %s %s", method, url, protocol);
    printf("Received request: %s %s %s\n", method, url, protocol);

    if (strstr(url, "http://") == url) {
        hostname = url + 7;
    } else {
        send(client_socket, "HTTP/1.1 400 Bad Request\n\n", 27, 0);
        close(client_socket);
        return;
    }

    char *path = strchr(hostname, '/');
    if (path) {
        *path = 0; // null-terminate the hostname
        path++;
    } else {
        path = ""; // no path, empty string
    }

    port_str = strchr(hostname, ':');
    if (port_str) {
        *port_str = 0; // null-terminate the hostname
        port = atoi(port_str + 1);
    }

    printf("Connecting to %s on port %d\n", hostname, port);
    
    // Creating the server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        error("Error creating socket");
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connecting to the target server
    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Error connecting to server");
    }

    // Forward the request to the server
    send(server_socket, buffer, bytes_received, 0);

    // Receiving the response from the server
    while ((bytes_received = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_received, 0);
    }

    if (bytes_received < 0) {
        error("Error receiving data from server");
    }

    // Closing sockets
    close(server_socket);
    close(client_socket);
}

int main() {
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        error("Error creating proxy socket");
    }

    int opt = 1;
    setsockopt(proxy_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in proxy_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(PORT);
    
    // Bind the socket
    if (bind(proxy_socket, (struct sockaddr *)&proxy_addr, sizeof(proxy_addr)) < 0) {
        error("Error binding socket");
    }

    // Listening for incoming connections
    if (listen(proxy_socket, 5) < 0) {
        error("Error listening");
    }

    printf("Surprisingly simple HTTP proxy running on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            error("Error accepting connection");
        }

        printf("Client connected!\n");
        handle_client(client_socket);
    }

    // Closing the proxy socket (never reached)
    close(proxy_socket);
    return EXIT_SUCCESS;
}