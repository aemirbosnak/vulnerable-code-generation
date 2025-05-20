//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS], opt = 1;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    socklen_t addr_size = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int max_clients = 0;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to an address and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(PORT));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(server_socket);
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        close(server_socket);
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %s\n", PORT);

    while (1) {
        // Accept a new connection
        socklen_t client_size = sizeof(struct sockaddr_in);
        if ((client_socket[max_clients] = accept(server_socket, (struct sockaddr *)&client_addr[max_clients], &client_size)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("New client connected with IP address: %s and port: %d\n", inet_ntoa(client_addr[max_clients].sin_addr), ntohs(client_addr[max_clients].sin_port));

        // Add the new socket to the list of clients
        max_clients++;
    }

    return 0;
}