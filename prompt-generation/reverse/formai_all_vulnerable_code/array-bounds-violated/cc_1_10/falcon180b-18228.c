//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 4096

int main() {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen;
    int i = 0;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        printf("Waiting for connection...\n");
        addrlen = sizeof(client_addr[i]);
        client_socket[i] = accept(server_socket, (struct sockaddr *)&client_addr[i], &addrlen);

        if (client_socket[i] == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection established with client: %s:%d\n", inet_ntoa(client_addr[i].sin_addr), ntohs(client_addr[i].sin_port));

        i++;
    }

    return 0;
}