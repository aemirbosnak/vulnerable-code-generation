//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <fcntl.h>

#define PORT 8080
#define BUFFER_SIZE 8192
#define LISTEN_QUEUE 5

// Function prototypes
int create_server_socket();
void handle_client(int client_socket);
void fetch_from_server(const char* url, int client_socket);
void send_response(int client_socket, const char* response, size_t response_len);
void close_socket(int sock);

int main() {
    int server_socket = create_server_socket();
    printf("Proxy server running on port %d...\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }
        handle_client(client_socket);
    }

    close_socket(server_socket);
    return 0;
}

int create_server_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close_socket(sock);
        exit(EXIT_FAILURE);
    }

    if (listen(sock, LISTEN_QUEUE) < 0) {
        perror("Listening failed");
        close_socket(sock);
        exit(EXIT_FAILURE);
    }

    return sock;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (received < 0) {
        perror("Failed to receive data");
        close_socket(client_socket);
        return;
    }
    
    buffer[received] = '\0'; // Null-terminate the received data
    printf("Received request:\n%s\n", buffer);
    
    // Extract the URL
    char method[10];
    char url[256];
    sscanf(buffer, "%s %s", method, url);

    // Assuming a GET request
    if (strcmp(method, "GET") == 0) {
        fetch_from_server(url, client_socket);
    } else {
        send_response(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", 36);
    }
    
    close_socket(client_socket);
}

void fetch_from_server(const char* url, int client_socket) {
    char* hostname = strtok((char*)url, "/");
    char* path = url + strlen(hostname);
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Server socket creation failed");
        return;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Add DNS resolution here

    if (connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to backend server failed");
        close_socket(server_socket);
        return;
    }

    // Send the request to the server
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);
    send(server_socket, request, strlen(request), 0);

    // Receive response from the server
    char response[BUFFER_SIZE];
    int bytes_received;
    while ((bytes_received = recv(server_socket, response, sizeof(response), 0)) > 0) {
        send_response(client_socket, response, bytes_received);
    }

    close_socket(server_socket);
}

void send_response(int client_socket, const char* response, size_t response_len) {
    send(client_socket, response, response_len, 0);
}

void close_socket(int sock) {
    close(sock);
}