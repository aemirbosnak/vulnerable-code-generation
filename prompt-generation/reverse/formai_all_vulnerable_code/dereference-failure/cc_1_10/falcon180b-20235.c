//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_read;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFERSIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(listen_socket, 10) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_read = recv(client_socket, buffer, BUFFERSIZE, 0)) > 0) {
            send(client_socket, buffer, bytes_read, 0);
        }

        close(client_socket);
    }

    return 0;
}