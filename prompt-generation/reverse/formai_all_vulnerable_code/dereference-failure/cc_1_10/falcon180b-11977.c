//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int new_socket;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addrlen;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    int max_clients = 0;
    int client_sockets[MAX_CLIENTS];

    if (argc!= 2) {
        printf("Usage:./server <port>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", atoi(argv[1]));

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (max_clients >= MAX_CLIENTS) {
            send(new_socket, "Server is full\n", strlen("Server is full\n"), 0);
            close(new_socket);
            continue;
        }

        client_sockets[max_clients] = new_socket;
        max_clients++;

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    return 0;
}