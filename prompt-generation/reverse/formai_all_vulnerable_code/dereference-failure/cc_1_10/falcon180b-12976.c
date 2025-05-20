//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, port;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    strcpy(buffer, argv[2]);

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(buffer);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        socklen_t client_size;
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char *request = "GET / HTTP/1.1\r\nHost: ";
        strcat(request, buffer);
        strcat(request, "\r\nConnection: close\r\n\r\n");

        send(client_socket, request, strlen(request), 0);

        char response[MAX_LINE];
        memset(response, 0, MAX_LINE);

        while (recv(client_socket, buffer, MAX_LINE, 0) > 0) {
            strcat(response, buffer);
        }

        printf("Response: %s\n", response);

        close(client_socket);
    }

    return 0;
}