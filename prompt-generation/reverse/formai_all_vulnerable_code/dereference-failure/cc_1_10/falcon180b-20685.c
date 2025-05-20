//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, addrlen, new_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = TRUE;
    int max_clients = 0;
    char *message = "Welcome to the server\n";

    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %s\n", argv[1]);

    while (opt) {
        addrlen = sizeof(struct sockaddr_in);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        if (max_clients == MAX_CLIENTS - 1) {
            send(new_socket, "Server is full\n", strlen("Server is full\n"), 0);
            close(new_socket);
        } else {
            max_clients++;
            send(new_socket, message, strlen(message), 0);
        }
    }

    close(server_socket);
    return 0;
}