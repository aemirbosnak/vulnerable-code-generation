//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket;
        socklen_t client_addr_size;
        struct sockaddr_in client_addr;

        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client sent: %s\n", buffer);

        if (strcmp(buffer, "bye") == 0) {
            break;
        }

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
}