//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8888
#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void handle_client(int client_socket);
void forward_request(int client_socket, const char *target_host, int target_port);
void send_response(int client_socket, int server_socket);
void read_request(int client_socket, char *buffer);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR on binding");

    listen(server_socket, 5);
    printf("Proxy server listening on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) error("ERROR on accept");

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char request[BUFFER_SIZE];

    read_request(client_socket, request);
    
    char method[10], url[256], protocol[10];
    sscanf(request, "%s %s %s", method, url, protocol);
    
    // Parse the URL to get the host and port
    char *host_start = strstr(url, "://");
    host_start = host_start ? host_start + 3 : url;

    char *host_end = strchr(host_start, '/');
    if (host_end) *host_end = '\0';

    char *port_str = strchr(host_start, ':');
    int target_port = 80;  // Default HTTP port
    if (port_str) {
        *port_str = '\0';
        target_port = atoi(port_str + 1);
    }
    
    printf("Proxying request to host: %s, port: %d\n", host_start, target_port);

    forward_request(client_socket, host_start, target_port);
}

void forward_request(int client_socket, const char *target_host, int target_port) {
    int server_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) error("ERROR opening socket to target host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    
    if (inet_pton(AF_INET, target_host, &server_addr.sin_addr) <= 0) {
        error("ERROR invalid address/ Address not supported");
    }

    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting to target host");
    }

    // Read the request from the client and send it to the server
    char request[BUFFER_SIZE];
    read(client_socket, request, BUFFER_SIZE);
    send(server_socket, request, strlen(request), 0);

    // Send back the response from the server to the client
    send_response(client_socket, server_socket);

    close(server_socket);
}

void send_response(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t n;

    while ((n = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_socket, buffer, n, 0);
    }
}

void read_request(int client_socket, char *buffer) {
    ssize_t bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_read < 0) error("ERROR reading from socket");
    buffer[bytes_read] = '\0';  // Null-terminate the request
}