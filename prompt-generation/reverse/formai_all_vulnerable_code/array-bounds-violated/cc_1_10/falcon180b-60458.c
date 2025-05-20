//Falcon-180B DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, client_address_size;
    struct sockaddr_in server_address, client_address[MAX_CLIENTS];
    char message[BUFFER_SIZE];
    int opt = 1;
    int client_count = 0;

    printf("Chat Server started...\n");

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

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(5000);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on the socket
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        // Accept a new connection
        if ((client_socket[client_count] = accept(server_socket, (struct sockaddr *)&client_address[client_count], &client_address_size)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address[client_count].sin_addr), ntohs(client_address[client_count].sin_port));

        // Send welcome message to client
        send(client_socket[client_count], "Welcome to the chat server!\n", strlen("Welcome to the chat server!\n"), 0);

        client_count++;
    }

    return 0;
}