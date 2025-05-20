//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, max_socket;
    int opt = 1;
    socklen_t addr_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int client_count = 0;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS)) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        client_count++;
        printf("Client %d connected\n", client_count);

        if (client_count >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.\n", BUFFER_SIZE, 0);
            close(client_socket);
            continue;
        }

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                printf("Client %d disconnected\n", client_count);
                close(client_socket);
                break;
            }

            printf("Client %d sent message: %s\n", client_count, buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending message to client %d\n", client_count);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}