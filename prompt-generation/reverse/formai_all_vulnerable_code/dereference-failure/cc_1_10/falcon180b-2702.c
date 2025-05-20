//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void handle_request(int client_socket) {
    char request[BUFFER_SIZE];
    memset(request, 0, BUFFER_SIZE);
    int bytes_received = recv(client_socket, request, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Client disconnected\n");
        close(client_socket);
        return;
    }
    printf("Received request: %s\n", request);

    char *method = strtok(request, " ");
    if (strcmp(method, "GET")!= 0) {
        send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n", 77, 0);
        close(client_socket);
        return;
    }

    char *path = strtok(NULL, " ");
    if (path == NULL) {
        send(client_socket, "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n", 61, 0);
        close(client_socket);
        return;
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    inet_pton(AF_INET, path, &server_addr.sin_addr);

    connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);
    while (recv(server_socket, response, BUFFER_SIZE, 0) > 0) {
        send(client_socket, response, strlen(response), 0);
        memset(response, 0, BUFFER_SIZE);
    }

    close(server_socket);
    close(client_socket);
}

int main(int argc, char *argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    printf("Proxy server started on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        handle_request(client_socket);
    }

    return 0;
}