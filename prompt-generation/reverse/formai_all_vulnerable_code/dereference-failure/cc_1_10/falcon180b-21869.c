//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define PORT 8080
#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 4096

int main() {
    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted\n");

        char request[MAX_REQUEST_SIZE];
        memset(request, 0, MAX_REQUEST_SIZE);

        int bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving request: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        printf("Request received: %s\n", request);

        char response[MAX_RESPONSE_SIZE];
        memset(response, 0, MAX_RESPONSE_SIZE);

        snprintf(response, MAX_RESPONSE_SIZE, "HTTP/1.0 200 OK\r\nContent-Length: %d\r\n\r\n", strlen("Hello, world! "));

        send(client_socket, response, strlen(response), 0);

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}