//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

void handle_request(int client_socket, char* request) {
    int request_length = strlen(request);
    char response[1024];
    snprintf(response, sizeof(response), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>");
    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}

int main(int argc, char* argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, 5) < 0) {
        perror("Failed to listen on socket");
        exit(EXIT_FAILURE);
    }
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }
        char request[1024];
        int request_length = recv(client_socket, request, sizeof(request), 0);
        if (request_length < 0) {
            perror("Failed to read request");
            close(client_socket);
            continue;
        }
        request[request_length] = '\0';
        handle_request(client_socket, request);
        close(client_socket);
    }
    close(server_socket);
    return 0;
}