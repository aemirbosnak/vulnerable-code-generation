//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number.\n");
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket.\n");
        close(listen_socket);
        return 1;
    }

    if (listen(listen_socket, 5) == -1) {
        fprintf(stderr, "Error listening on socket.\n");
        close(listen_socket);
        return 1;
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, NULL);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection.\n");
            close(client_socket);
            continue;
        }

        fprintf(stdout, "Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                fprintf(stdout, "Client disconnected.\n");
                close(client_socket);
                break;
            }

            fprintf(stdout, "Received: %s", buffer);

            ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent == -1) {
                fprintf(stderr, "Error sending data.\n");
                close(client_socket);
                break;
            }
        }
    }

    close(listen_socket);
    return 0;
}