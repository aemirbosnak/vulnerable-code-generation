//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_request(int client_socket) {
    char request[BUFFER_SIZE];
    bzero(request, BUFFER_SIZE);
    recv(client_socket, request, BUFFER_SIZE, 0);

    printf("Received request: %s\n", request);

    char *method = strtok(request, " ");
    char *path = strtok(NULL, " ");

    if (strcmp(method, "GET") == 0) {
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen("Hello from the proxy!"));
        send(client_socket, response, strlen(response), 0);
    } else {
        char response[BUFFER_SIZE];
        sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: %d\r\n\r\n", strlen("404 Not Found"));
        send(client_socket, response, strlen(response), 0);
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        printf("Client connected: %d\n", client_socket);

        handle_request(client_socket);

        close(client_socket);
    }

    return 0;
}