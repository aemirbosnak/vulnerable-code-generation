//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 5
#define MAX_REQUEST_LENGTH 1024

void handle_request(int client_socket) {
    char request[MAX_REQUEST_LENGTH];
    memset(request, 0, MAX_REQUEST_LENGTH);

    int bytes_received = recv(client_socket, request, MAX_REQUEST_LENGTH, 0);

    if (bytes_received <= 0) {
        close(client_socket);
        return;
    }

    printf("Received request: %s\n", request);

    char response[MAX_REQUEST_LENGTH];
    strcpy(response, "HTTP/1.1 200 OK\r\nContent-Length: 13\r\n\r\nHello, World!");

    send(client_socket, response, strlen(response), 0);

    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("New client connected\n");

        handle_request(client_socket);
    }

    return 0;
}