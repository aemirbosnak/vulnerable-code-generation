//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, new_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    int i, j, max_clients = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    // Initialize server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // Bind the socket to an address and port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        max_clients++;

        // Add the new socket to the array of client sockets
        for (i = 0; i < max_clients - 1; i++) {
            client_socket[i] = client_socket[i + 1];
        }

        client_socket[max_clients - 1] = new_socket;

        // Notify all clients that a new client has joined
        send(client_socket[0], "New client joined\n", strlen("New client joined\n"), 0);
    }

    return 0;
}