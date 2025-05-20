//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096

// Function prototypes
void start_proxy();
void handle_client(int client_socket);
void forward_request(int client_socket, const char *request);
void send_response(int client_socket, int server_socket);

int main() {
    start_proxy();
    return 0;
}

void start_proxy() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d...\n", PORT);

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
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    bytes_read = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_read < 0) {
        perror("Receive failed");
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Received request:\n%s\n", buffer);

    forward_request(client_socket, buffer);
}

void forward_request(int client_socket, const char *request) {
    char method[16], host[256], path[256], full_request[BUFFER_SIZE];
    int server_socket;
    struct sockaddr_in server_addr;
    char *host_header;

    sscanf(request, "%s %s %*s", method, path); // Extract method and path

    host_header = strstr(request, "Host: ");
    if (host_header) {
        sscanf(host_header, "Host: %s", host);
    } else {
        fprintf(stderr, "Host header not found!\n");
        return;
    }

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP for example.com

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to server failed");
        close(server_socket);
        return;
    }

    snprintf(full_request, sizeof(full_request), "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", method, path, host);
    send(server_socket, full_request, strlen(full_request), 0);
    send_response(client_socket, server_socket);

    close(server_socket);
}

void send_response(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    while ((bytes_read = recv(server_socket, buffer, sizeof(buffer), 0)) > 0) {
        send(client_socket, buffer, bytes_read, 0);
    }

    if (bytes_read < 0) {
        perror("Receive from server failed");
    }
}