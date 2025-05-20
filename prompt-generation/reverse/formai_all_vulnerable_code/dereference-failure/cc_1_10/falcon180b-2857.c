//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, new_socket, addrlen, bytes_received, client_socket[MAX_CLIENTS], i;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        close(server_socket);
        return 1;
    }

    printf("Server started on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        for (i = 0; i < MAX_CLIENTS; i++) {
            if (client_socket[i] == 0) {
                client_socket[i] = new_socket;
                break;
            }
        }

        if (i == MAX_CLIENTS) {
            printf("Maximum clients reached\n");
            close(new_socket);
            continue;
        }

        printf("New client connected on socket %d\n", new_socket);
    }

    return 0;
}