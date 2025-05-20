//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 0;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        return 0;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 0;
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 0;
    }

    printf("Listening on port %s...\n", argv[1]);

    while (TRUE) {
        addrlen = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            memset(buffer, 0, MAX_LINE);
            if (recv(client_socket, buffer, MAX_LINE, 0) <= 0) {
                printf("Error receiving data\n");
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}