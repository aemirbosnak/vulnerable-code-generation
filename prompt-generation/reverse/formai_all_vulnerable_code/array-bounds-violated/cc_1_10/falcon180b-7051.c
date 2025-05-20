//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 5
#define BUF_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        int client_socket;
        if ((client_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUF_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s", buffer);

        char* response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n<!DOCTYPE html><html><head><title>Simple Web Server</title></head><body><h1>Hello, World!</h1></body></html>";
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
}