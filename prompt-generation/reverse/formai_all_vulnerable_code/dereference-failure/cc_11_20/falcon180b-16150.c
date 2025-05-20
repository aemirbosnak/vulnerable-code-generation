//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    int opt = 1;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(client_addr);
    int client_count = 0;

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        if (client_count >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", strlen("Server is full. Please try again later.\n"), 0);
            close(client_socket);
            continue;
        }

        client_count++;
        printf("Client connected. Total clients: %d\n", client_count);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                if (errno!= EAGAIN) {
                    printf("Client disconnected\n");
                    close(client_socket);
                    client_count--;
                }
                break;
            }

            printf("Received message: %s", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0)!= strlen(buffer)) {
                printf("Send failed\n");
                close(client_socket);
                client_count--;
                break;
            }
        }
    }

    close(listen_socket);
    return 0;
}