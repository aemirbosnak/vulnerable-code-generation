//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
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
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    puts("Server is listening on port 8080...");

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size)) == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        puts("Client connected");

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0)
                    puts("Client disconnected");
                else
                    perror("recv");

                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            ssize_t bytes_sent = send(client_socket, buffer, strlen(buffer), 0);

            if (bytes_sent == -1) {
                perror("send");
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}