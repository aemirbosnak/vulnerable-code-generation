//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFF_SIZE 4096

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in listen_addr, client_addr;
    char buffer[BUFF_SIZE];
    int addrlen;
    int bytes_received;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(atoi(argv[1]));
    listen_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Proxy server listening on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        bytes_received = 0;
        while ((bytes_received = recv(client_socket, buffer, BUFF_SIZE, 0)) > 0) {
            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    return 0;
}