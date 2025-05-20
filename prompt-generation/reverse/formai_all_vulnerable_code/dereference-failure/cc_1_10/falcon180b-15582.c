//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define DOCUMENT_ROOT "./www"

char *get_response(char *request) {
    char *response = malloc(MAX_REQUEST_SIZE * 2);
    strcpy(response, "HTTP/1.1 200 OK\r\n");
    strcat(response, "Content-Type: text/html\r\n");
    strcat(response, "Connection: close\r\n");
    strcat(response, "\r\n");
    strcat(response, "<html><head><title>Welcome to Ada Lovelace's Simple Web Server!</title></head><body>");
    strcat(response, "<h1>Hello, World!</h1>");
    strcat(response, "</body></html>");
    return response;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char request[MAX_REQUEST_SIZE];
        memset(request, 0, MAX_REQUEST_SIZE);

        int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving request\n");
            close(client_socket);
            continue;
        }

        char *response = get_response(request);
        send(client_socket, response, strlen(response), 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}