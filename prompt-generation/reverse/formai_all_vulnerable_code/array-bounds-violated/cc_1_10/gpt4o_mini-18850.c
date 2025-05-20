//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192

void handle_client(int client_socket);
void recursive_proxy_request(int client_socket, const char *hostname, int port);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", port);
    
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accept failed");
            continue;
        }
        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (received < 0) {
        perror("Receive failed");
        return;
    }
    buffer[received] = '\0';

    char method[4], uri[256];
    sscanf(buffer, "%s %s", method, uri);
    
    if (strcasecmp(method, "GET") != 0) {
        fprintf(stderr, "Only GET requests are supported.\n");
        return;
    }

    char hostname[256];
    int port = 80; // Default HTTP port
    sscanf(uri, "http://%255[^:]:%d", hostname, &port);
    printf("Proxying request to %s:%d\n", hostname, port);
    
    recursive_proxy_request(client_socket, hostname, port);
}

void recursive_proxy_request(int client_socket, const char *hostname, int port) {
    int server_socket;
    struct sockaddr_in server_addr;
    struct hostent *host;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        return;
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hostname);
        close(server_socket);
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(server_socket);
        return;
    }

    char http_request[BUFFER_SIZE];
    snprintf(http_request, sizeof(http_request), 
             "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);
    send(server_socket, http_request, strlen(http_request), 0);
    
    char response_buffer[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_socket, response_buffer, sizeof(response_buffer) - 1, 0)) > 0) {
        response_buffer[bytes_received] = '\0';
        send(client_socket, response_buffer, bytes_received, 0);
    }

    if (bytes_received < 0) {
        perror("Response receive failed");
    }

    close(server_socket);
}