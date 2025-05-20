//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int master_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    // Create socket
    if ((master_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Bind the socket
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    if (bind(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(master_socket, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8000\n");

    while(1) {
        // Accept a connection
        if ((client_socket[client_count] = accept(master_socket, (struct sockaddr *)&client_addr[client_count], (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Add socket to master list
        printf("New client connected\n");
        client_count++;
    }

    return 0;
}