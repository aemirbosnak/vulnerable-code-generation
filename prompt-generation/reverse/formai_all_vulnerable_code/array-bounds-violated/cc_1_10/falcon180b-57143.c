//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], max_socket, client_size;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];

    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        // accept connection
        if ((client_socket[0] = accept(server_socket, (struct sockaddr *)&client_addr[0], (socklen_t*)&client_size)) < 0) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        // find an available socket
        for (max_socket = 1; max_socket < MAX_CLIENTS; max_socket++) {
            if (client_socket[max_socket] == 0) {
                break;
            }
        }

        // move the new socket to the available socket
        client_socket[max_socket] = client_socket[0];
        client_socket[0] = 0;

        // print client info
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr[0].sin_addr), ntohs(client_addr[0].sin_port));
    }

    return 0;
}