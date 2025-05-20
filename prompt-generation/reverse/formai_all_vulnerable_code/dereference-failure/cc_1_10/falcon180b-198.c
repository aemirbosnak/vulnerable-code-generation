//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080
#define BACKLOG 5
#define MAX_SIZE 1024

void *handler(void *client_socket) {
    int client_socket_d = *(int *) client_socket;
    char buffer[MAX_SIZE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_socket_d, buffer, MAX_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client_socket_d, buffer);
        send(client_socket_d, buffer, strlen(buffer), 0);
    }

    close(client_socket_d);
    free(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    if (server_socket == -1) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Failed to bind socket.\n");
        exit(2);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Failed to listen on socket.\n");
        exit(3);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Failed to accept connection.\n");
            exit(4);
        }

        void *client_socket_ptr = malloc(sizeof(int));
        *(int *) client_socket_ptr = client_socket;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handler, client_socket_ptr);
    }

    return 0;
}