//Falcon-180B DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[BUF_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        handle_client(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUF_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUF_SIZE, 0))!= 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }
}