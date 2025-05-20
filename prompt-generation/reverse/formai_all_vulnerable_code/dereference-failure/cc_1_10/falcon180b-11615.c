//Falcon-180B DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[BUFFER_SIZE];
    int client_sockets[MAX_CLIENTS];
    int max_clients = 0;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
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
        printf("Error listening socket\n");
        exit(1);
    }

    addrlen = sizeof(client_addr);

    while (1) {
        printf("Waiting for client connection...\n");

        if (max_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            continue;
        }

        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        client_sockets[max_clients] = client_socket;
        max_clients++;

        printf("Client connected on socket %d\n", client_socket);
    }

    return 0;
}