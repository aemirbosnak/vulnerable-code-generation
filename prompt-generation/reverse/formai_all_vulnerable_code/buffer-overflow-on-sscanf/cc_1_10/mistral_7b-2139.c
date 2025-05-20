//MISTRAL-7B DATASET v1.0 Category: Simple Web Server ; Style: complete
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

bool setup(int* server_fd, int* new_socket) {
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);

    if ((*server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        return false;
    }

    if (setsockopt(*server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt)) < 0) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(*server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(*server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    if ((*new_socket = accept(*server_fd, NULL, NULL)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    return true;
}

void handle_client(int new_socket) {
    char buffer[BUFFER_SIZE] = {0};
    ssize_t read_size;

    // Receive a request from client
    read_size = recv(new_socket, buffer, BUFFER_SIZE, 0);
    if (read_size < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Received request:\n%s\n", buffer);

    // Parse the request
    char method[8], path[256], protocol[16];
    sscanf(buffer, "%s %s %s", method, path, protocol);

    // Generate a response
    char response[BUFFER_SIZE];
    snprintf(response, BUFFER_SIZE,
             "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>");

    // Send the response to the client
    send(new_socket, response, strlen(response), 0);

    // Close the connection
    close(new_socket);
}

int main() {
    int server_fd, new_socket;

    if (setup(&server_fd, &new_socket) == false) {
        perror("setup failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (true) {
        handle_client(new_socket);
    }

    return 0;
}