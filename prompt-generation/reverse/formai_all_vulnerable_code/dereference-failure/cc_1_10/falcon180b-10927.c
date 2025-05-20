//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096
#define PORT 8080

int main(int argc, char *argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        char request[MAX_REQUEST_SIZE];
        memset(request, 0, MAX_REQUEST_SIZE);
        recv(client_socket, request, MAX_REQUEST_SIZE, 0);

        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");

        if (strcmp(method, "GET") == 0) {
            if (strcmp(path, "/") == 0) {
                char response[MAX_RESPONSE_SIZE];
                sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n<html><body><h1>Welcome to the server!</h1></body></html>", strlen(response));
                send(client_socket, response, strlen(response), 0);
            } else {
                char response[MAX_RESPONSE_SIZE];
                sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n<html><body><h1>404 Not Found</h1></body></html>", strlen(response));
                send(client_socket, response, strlen(response), 0);
            }
        } else {
            char response[MAX_RESPONSE_SIZE];
            sprintf(response, "HTTP/1.1 405 Method Not Allowed\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n<html><body><h1>405 Method Not Allowed</h1></body></html>", strlen(response));
            send(client_socket, response, strlen(response), 0);
        }

        close(client_socket);
    }

    return 0;
}