//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_REQUEST_LENGTH 4096
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    char buffer[MAX_REQUEST_LENGTH];
    char response[MAX_RESPONSE_LENGTH];
    int nbytes;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 10) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        while ((nbytes = recv(client_socket, buffer, MAX_REQUEST_LENGTH, 0)) > 0) {
            buffer[nbytes] = '\0';
            send(client_socket, buffer, nbytes, 0);
        }

        close(client_socket);
    }

    close(listen_socket);

    return 0;
}