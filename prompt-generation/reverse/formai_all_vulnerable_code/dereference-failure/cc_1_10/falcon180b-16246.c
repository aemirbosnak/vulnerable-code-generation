//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TRUE 1
#define FALSE 0

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Proxy server started on port %s\n", argv[1]);

    while (TRUE) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(client_socket);
            continue;
        }

        send(client_socket, buffer, bytes_received, 0);
        close(client_socket);
    }

    close(listen_socket);
    return 0;
}