//Falcon-180B DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = 0, new_socket, addrlen;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];

    // Initialize server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    // Bind server socket to port 8000
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Listen on server socket for incoming connections
    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server is running on port 8000...\n");

    // Accept incoming connections and handle client requests
    while (1) {
        addrlen = sizeof(client_addr[max_clients]);
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen)) == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr[max_clients].sin_addr), ntohs(client_addr[max_clients].sin_port));

        // Send welcome message to client
        if (send(new_socket, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0) == -1) {
            printf("Error sending data: %s\n", strerror(errno));
            exit(1);
        }

        if (max_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached.\n");
            close(new_socket);
            continue;
        }

        client_socket[max_clients] = new_socket;
        max_clients++;
    }

    return 0;
}