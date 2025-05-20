//GPT-4o-mini DATASET v1.0 Category: Simple Web Server ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define ROOT_FOLDER "www"

void handle_client(int client_socket);
void send_response(int client_socket, const char *status, const char *content_type, const char *body);
void send_file(int client_socket, const char *filename);
void not_found(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configuring server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }
    printf("Server is running on port %d...\n", PORT);

    // Accepting clients in a loop
    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Accepting client failed");
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
    char method[16], path[128], version[16];

    // Reading the request from the client
    recv(client_socket, buffer, sizeof(buffer), 0);
    sscanf(buffer, "%s %s %s", method, path, version);

    // Only accept GET method
    if (strcasecmp(method, "GET") == 0) {
        // Remove the leading slash and serve the file
        char filepath[144];
        snprintf(filepath, sizeof(filepath), "%s%s", ROOT_FOLDER, path);

        // Handle root directory
        if (strcmp(path, "/") == 0) {
            strcat(filepath, "index.html");
        }

        send_file(client_socket, filepath);
    } else {
        send_response(client_socket, "HTTP/1.1 405 Method Not Allowed", "text/plain", "Method Not Allowed");
    }
}

void send_response(int client_socket, const char *status, const char *content_type, const char *body) {
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response),
             "%s\r\n"
             "Content-Type: %s\r\n"
             "Content-Length: %lu\r\n"
             "Connection: close\r\n"
             "\r\n"
             "%s",
             status, content_type, strlen(body), body);

    send(client_socket, response, strlen(response), 0);
}

void send_file(int client_socket, const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file != NULL) {
        char buffer[BUFFER_SIZE];
        fseek(file, 0, SEEK_END);
        long file_size = ftell(file);
        fseek(file, 0, SEEK_SET);

        snprintf(buffer, sizeof(buffer), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %ld\r\n\r\n", file_size);
        send(client_socket, buffer, strlen(buffer), 0);

        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            send(client_socket, buffer, strlen(buffer), 0);
        }

        fclose(file);
    } else {
        not_found(client_socket);
    }
}

void not_found(int client_socket) {
    send_response(client_socket, "HTTP/1.1 404 Not Found", "text/plain", "404 Not Found");
}