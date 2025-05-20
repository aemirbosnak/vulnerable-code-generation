//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                if (errno!= EAGAIN) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);

            if (strcmp(buffer, "bye") == 0) {
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}