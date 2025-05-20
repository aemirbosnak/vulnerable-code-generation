//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CONNECTIONS 10

int current_connections = 0;
int server_socket_fd;

void handle_client(int client_socket_fd) {
    printf("Client %d connected\n", client_socket_fd);
    char buffer[256];
    int n = recv(client_socket_fd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        printf("Error reading from socket\n");
    } else {
        buffer[n] = '\0';
        printf("Received message: %s\n", buffer);
        if (strcmp(buffer, "disconnect") == 0) {
            printf("Client %d disconnected\n", client_socket_fd);
            close(client_socket_fd);
            current_connections--;
            return;
        }
    }
    handle_client(client_socket_fd);
}

void handle_connections() {
    while (current_connections < MAX_CONNECTIONS) {
        int client_socket_fd;
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_address, &client_address_len);
        current_connections++;
        handle_client(client_socket_fd);
    }
}

void start_server() {
    int opt = 1;
    struct sockaddr_in address;

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket options\n");
        exit(1);
    }

    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_port = htons(SERVER_PORT);

    if (bind(server_socket_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket_fd, 1) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);
    handle_connections();
}

int main() {
    start_server();
    return 0;
}