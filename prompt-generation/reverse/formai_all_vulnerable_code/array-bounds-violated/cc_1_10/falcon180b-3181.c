//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_REQUEST_LENGTH 1024
#define HTML_HEADER "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n"

void handle_request(int client_socket) {
    char request[MAX_REQUEST_LENGTH];
    int bytes_received = 0;

    while (bytes_received < MAX_REQUEST_LENGTH) {
        bytes_received += recv(client_socket, request + bytes_received, MAX_REQUEST_LENGTH - bytes_received, 0);
    }

    request[bytes_received] = '\0';

    if (strstr(request, "GET / HTTP/1.1") == NULL) {
        send(client_socket, "HTTP/1.1 400 Bad Request\r\n\r\n", strlen("HTTP/1.1 400 Bad Request\r\n\r\n"), 0);
    } else {
        send(client_socket, HTML_HEADER, strlen(HTML_HEADER), 0);
        send(client_socket, "<h1>Hello, World!</h1>", strlen("<h1>Hello, World!</h1>"), 0);
    }

    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted\n");
        handle_request(client_socket);
    }

    close(server_socket);
    return 0;
}