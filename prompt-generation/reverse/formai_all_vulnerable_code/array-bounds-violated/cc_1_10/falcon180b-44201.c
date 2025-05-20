//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 8192

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_size;
    char request[MAX_REQUEST_SIZE];
    char response[MAX_RESPONSE_SIZE];
    char *response_ptr = response;
    char *request_ptr = request;
    int request_size = 0;
    int response_size = 0;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size)) == -1) {
            perror("accept");
            exit(1);
        }

        memset(request, 0, MAX_REQUEST_SIZE);
        while ((request_size < MAX_REQUEST_SIZE - 1) && ((request_size = recv(client_socket, request + request_size, 1, 0)) > 0)) {
            if (request[request_size - 1] == '\r') {
                request[request_size - 1] = 0;
                break;
            }
        }

        printf("Received request: %s\n", request);

        if (strcmp(request, "GET / HTTP/1.1") == 0) {
            response_size = sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen("<html><body><h1>Hello, World!</h1></body></html>"));
            response[response_size] = 0;
            send(client_socket, response, response_size, 0);
        } else {
            response_size = sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n", strlen("<html><body><h1>Not Found</h1></body></html>"));
            response[response_size] = 0;
            send(client_socket, response, response_size, 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}