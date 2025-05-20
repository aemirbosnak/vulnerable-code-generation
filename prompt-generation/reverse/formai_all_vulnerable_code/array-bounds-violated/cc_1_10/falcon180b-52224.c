//Falcon-180B DATASET v1.0 Category: Chat server ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    int client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int max_clients = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket options\n");
        exit(1);
    }

    // Bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Chat server started on port 8080\n");

    while (1) {
        // Accept a new connection
        addrlen = sizeof(client_addr);
        if ((client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Add the new socket to the array of client sockets
        client_socket[max_clients] = client_socket[max_clients];
        max_clients++;
    }

    return 0;
}