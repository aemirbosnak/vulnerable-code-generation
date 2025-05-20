//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen, opt = 1;
    int max_clients = 0;

    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    // bind socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // listen on socket
    if (listen(server_socket, 10) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        // accept client connection
        addrlen = sizeof(client_addr[max_clients]);
        if ((client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen)) < 0) {
            printf("Error accepting client connection\n");
            exit(1);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[max_clients].sin_addr), ntohs(client_addr[max_clients].sin_port));

        // send welcome message to client
        send(client_socket[max_clients], "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);

        // add client socket to master list
        max_clients++;
    }

    return 0;
}