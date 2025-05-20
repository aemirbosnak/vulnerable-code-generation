//GPT-4o-mini DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 8192
#define PORT 8080
#define MAX_CONNECTIONS 100

void handle_client(int client_socket);
void parse_request(char *request);
void send_response(int client_socket, const char *response);
int create_server_socket(int port);

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int port = PORT; // Default port

    if (argc > 1) {
        port = atoi(argv[1]); // Allow port configuration via command line
    }

    server_socket = create_server_socket(port);
    printf("[INFO] Proxy server listening on port %d\n", port);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("[ERROR] Accept failed");
            continue;
        }
        printf("[INFO] Accepted connection\n");

        handle_client(client_socket);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    bytes_received = recv(client_socket, buffer, sizeof(buffer) - 1, 0);
    if (bytes_received < 0) {
        perror("[ERROR] Receive failed");
        return;
    }
    buffer[bytes_received] = '\0';

    printf("[INFO] Request received:\n%s\n", buffer);
    parse_request(buffer);

    const char *response = "HTTP/1.1 200 OK\r\nContent-Length: 12\r\n\r\nHello World\0";
    send_response(client_socket, response);
}

void parse_request(char *request) {
    char method[10], url[256], protocol[10];

    sscanf(request, "%s %s %s", method, url, protocol);
    printf("[INFO] Method: %s, URL: %s, Protocol: %s\n", method, url, protocol);
}

void send_response(int client_socket, const char *response) {
    int response_length = strlen(response);
    int bytes_sent = send(client_socket, response, response_length, 0);
    if (bytes_sent < 0) {
        perror("[ERROR] Send failed");
    } else {
        printf("[INFO] Sent response to client (%d bytes)\n", bytes_sent);
    }
}

int create_server_socket(int port) {
    int server_socket;
    struct sockaddr_in server_addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("[ERROR] Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("[ERROR] Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("[ERROR] Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    return server_socket;
}