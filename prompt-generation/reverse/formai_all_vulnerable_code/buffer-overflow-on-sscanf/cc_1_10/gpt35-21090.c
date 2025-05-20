//FormAI DATASET v1.0 Category: Simple Web Server ; Style: genious
// A simple web server written in C by a coding genius!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

// Function declarations
void handle_request(int socket_fd);
void send_file(int client_fd, char* file_path);
void send_error(int client_fd, char* error_code);

int main(int argc, char** argv) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    unsigned int client_addr_len;
    int opt = 1;

    // Create a server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Could not create server socket\n");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options to reuse address and port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Could not set socket options\n");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to port 8080
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind server socket to port 8080\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming requests
    if (listen(server_fd, 10) < 0) {
        printf("Could not listen for incoming requests\n");
        exit(EXIT_FAILURE);
    }

    // Handle incoming requests
    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
            printf("Could not accept incoming request\n");
            continue;
        }
        handle_request(client_fd);
        close(client_fd);
    }

    return 0;
}

// Handle incoming requests
void handle_request(int client_fd) {
    char buffer[BUFFER_SIZE];
    char method[10], url[500], http_version[50];
    char file_path[500];
    FILE* file;

    // Receive request
    recv(client_fd, buffer, BUFFER_SIZE, 0);
    sscanf(buffer, "%s %s %s", method, url, http_version);

    // Check if method is GET and HTTP version is 1.1
    if (strcmp(method, "GET") == 0 && strcmp(http_version, "HTTP/1.1") == 0) {

        // Get file path from URL
        sprintf(file_path, ".%s", url);

        // Open file
        file = fopen(file_path + 1, "r");

        // Send file if exists, else send 404 error
        if (file != NULL) {
            send_file(client_fd, file_path);
            fclose(file);
        } else {
            send_error(client_fd, "404");
        }

    } else {
        // Send 400 error for bad request
        send_error(client_fd, "400");
    }
}

// Send file contents
void send_file(int client_fd, char* file_path) {
    FILE* file;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    file = fopen(file_path + 1, "r");

    // Send HTTP header
    send(client_fd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n", 44, 0);

    // Send file data
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0) {
        send(client_fd, buffer, bytes_read, 0);
    }
}

// Send error page
void send_error(int client_fd, char* error_code) {
    char error_message[50];
    sprintf(error_message, "<html><body><h1>Error %s</h1></body></html>", error_code);

    send(client_fd, "HTTP/1.1 ", 9, 0);
    send(client_fd, error_code, strlen(error_code), 0);
    send(client_fd, " Not Found\r\nContent-Type: text/html\r\n\r\n", 42, 0);
    send(client_fd, error_message, strlen(error_message), 0);
}