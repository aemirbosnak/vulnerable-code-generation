//Falcon-180B DATASET v1.0 Category: Firewall ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t client_size;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to bind socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        fprintf(stderr, "Failed to listen on socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);

        if (client_socket == -1) {
            fprintf(stderr, "Failed to accept connection: %s\n", strerror(errno));
            continue;
        }

        fprintf(stdout, "Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            fprintf(stdout, "Received message: %s\n", buffer);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}