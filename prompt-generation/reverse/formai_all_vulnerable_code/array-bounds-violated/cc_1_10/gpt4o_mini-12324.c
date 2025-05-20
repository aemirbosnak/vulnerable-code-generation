//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

void initialize_server(int *server_fd, struct sockaddr_in *address);
void handle_client(int client_socket);
void forward_request(int client_socket, char *request);
void send_response(int client_socket, char *response, int length);

int main() {
    int server_fd;
    struct sockaddr_in address;

    initialize_server(&server_fd, &address);

    while (1) {
        int client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&(socklen_t){sizeof(address)});
        if (client_socket < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_fd);
    return 0;
}

void initialize_server(int *server_fd, struct sockaddr_in *address) {
    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    address->sin_family = AF_INET;
    address->sin_addr.s_addr = INADDR_ANY;
    address->sin_port = htons(PORT);

    if (bind(*server_fd, (struct sockaddr *)address, sizeof(*address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(*server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server is running on port %d\n", PORT);
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_read = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
    
    if (bytes_read <= 0) {
        perror("Failed to read from client");
        return;
    }

    buffer[bytes_read] = '\0';
    printf("Received request:\n%s\n", buffer);

    forward_request(client_socket, buffer);
}

void forward_request(int client_socket, char *request) {
    char host[256];
    int port = 80;
    char *request_line = strtok(request, "\r\n");
    
    if (sscanf(request_line, "GET http://%255[^/:]:%d", host, &port) == 2 ||
        sscanf(request_line, "GET http://%255[^/:]", host) == 1) {
        
        printf("Forwarding request to %s:%d\n", host, port);
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_address;

        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        inet_pton(AF_INET, host, &server_address.sin_addr);

        if (connect(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
            perror("Connection to server failed");
            return;
        }

        send(server_socket, request, strlen(request), 0);
        char response[BUFFER_SIZE];
        int bytes_received;

        while ((bytes_received = recv(server_socket, response, BUFFER_SIZE - 1, 0)) > 0) {
            send_response(client_socket, response, bytes_received);
        }

        close(server_socket);
    } else {
        printf("Invalid request format\n");
        const char *error_response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        send(client_socket, error_response, strlen(error_response), 0);
    }
}

void send_response(int client_socket, char *response, int length) {
    send(client_socket, response, length, 0);
}