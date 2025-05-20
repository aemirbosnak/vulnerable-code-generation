//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, client_socket_size;
    struct sockaddr_in server_addr, client_addr;
    char *message = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, World!</h1></body></html>";
    char buffer[MAX_REQUEST_SIZE];
    int num_clients = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %s\n", argv[1]);

    while (true) {
        client_socket_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_socket_size);

        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            continue;
        }

        num_clients++;

        if (num_clients > MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\r\n", strlen("Server is full. Please try again later.\r\n"), 0);
            close(client_socket);
            num_clients--;
            continue;
        }

        send(client_socket, message, strlen(message), 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}