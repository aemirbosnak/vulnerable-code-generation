//Falcon-180B DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;
    int client_socket[MAX_CLIENTS];
    int max_socket = 0;
    int addrlen;
    char buffer[BUFFER_SIZE];

    printf("Chat Server started on port %d\n", PORT);

    // create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set option on socket
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // fill address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen on socket
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // accept new connections
        addrlen = sizeof(struct sockaddr_in);
        if ((client_socket[max_socket] = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected on socket %d\n", client_socket[max_socket]);
        max_socket++;

        if (max_socket == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
        }
    }

    return 0;
}