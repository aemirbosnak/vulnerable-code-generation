//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Client connected on port %d\n", ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) == -1) {
                if (errno == ECONNRESET) {
                    printf("Client disconnected\n");
                    break;
                } else {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
            }

            printf("Received message: %s", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}