//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(struct sockaddr_in);
    int i, num_clients = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind server_socket to server_addr
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on server_socket
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", SERVER_PORT);

    while (1) {
        // Accept a new client connection
        if ((client_socket[num_clients] = accept(server_socket, (struct sockaddr *)&client_addr[num_clients], (socklen_t *)&addrlen)) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client %d connected\n", num_clients + 1);
        num_clients++;

        // Fork a new process to handle the client
        if (fork() == 0) {
            // Child process
            close(server_socket);
            for (i = 0; i < num_clients - 1; i++) {
                close(client_socket[i]);
            }

            while (1) {
                // Receive message from client
                memset(buffer, 0, BUFFER_SIZE);
                int bytes_received = recv(client_socket[num_clients - 1], buffer, BUFFER_SIZE, 0);
                if (bytes_received <= 0) {
                    printf("Client disconnected\n");
                    close(client_socket[num_clients - 1]);
                    exit(0);
                }

                // Echo message back to client
                send(client_socket[num_clients - 1], buffer, bytes_received, 0);
            }
        }
    }

    return 0;
}