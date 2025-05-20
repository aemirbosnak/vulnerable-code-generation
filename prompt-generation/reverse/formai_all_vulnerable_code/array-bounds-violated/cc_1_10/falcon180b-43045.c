//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_clients = 0, client_socket_index, new_socket;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int opt = 1;
    int addrlen = sizeof(client_addr[0]);

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("bind failed\n");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, BACKLOG) < 0) {
        printf("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &addrlen)) < 0) {
            printf("accept");
            exit(EXIT_FAILURE);
        }

        // Add the new socket to the array of clients
        client_socket[max_clients] = new_socket;
        max_clients++;

        // Notify all other clients that a new client has connected
        for (client_socket_index = 0; client_socket_index < max_clients - 1; client_socket_index++) {
            send(client_socket[client_socket_index], "New client connected\n", strlen("New client connected\n"), 0);
        }
    }

    return 0;
}