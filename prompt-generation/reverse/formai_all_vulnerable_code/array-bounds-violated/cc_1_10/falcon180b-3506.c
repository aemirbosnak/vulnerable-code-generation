//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], client_socket_count = 0;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    socklen_t client_addr_size;
    int opt = TRUE;

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    printf("Server started on IP address %s and port %d\n", argv[1], PORT);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        client_addr_size = sizeof(client_addr[0]);
        client_socket[client_socket_count] = accept(server_socket, (struct sockaddr *)&client_addr[client_socket_count], &client_addr_size);

        if (client_socket[client_socket_count] == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client connected on IP address %s and port %d\n", inet_ntoa(client_addr[client_socket_count].sin_addr), ntohs(client_addr[client_socket_count].sin_port));

        if (client_socket_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            exit(1);
        }

        client_socket_count++;
    }

    close(server_socket);

    return 0;
}