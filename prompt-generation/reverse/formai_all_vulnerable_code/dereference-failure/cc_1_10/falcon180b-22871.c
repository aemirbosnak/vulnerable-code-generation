//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define SERVER_PORT 80
#define SERVER_ADDRESS "127.0.0.1"

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc);

int main(int argc, char **argv) {
    int server_socket, client_socket, addrlen, new_socket;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port %s\n", argv[1]);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);

        if (new_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        if (client_count >= MAX_CLIENTS) {
            close(new_socket);
            printf("Too many clients\n");
            continue;
        }

        client_sockets[client_count++] = new_socket;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)new_socket);
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int client_socket = *(int *) socket_desc;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_socket);
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    return NULL;
}