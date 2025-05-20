//Falcon-180B DATASET v1.0 Category: Chat server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int client_socket;
    socklen_t addr_size;
    char *message;
    int message_len;

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Failed to listen on socket\n");
        exit(1);
    }

    while (1) {
        addr_size = sizeof(server_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&server_addr, &addr_size);
        if (client_socket == -1) {
            printf("Failed to accept connection\n");
            continue;
        }

        message = malloc(BUFFER_SIZE);
        memset(message, 0, BUFFER_SIZE);

        while ((message_len = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            strncat(message, buffer, message_len);
        }

        printf("Client %s sent message: %s\n", inet_ntoa(server_addr.sin_addr), message);

        send(client_socket, message, strlen(message), 0);
        free(message);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}