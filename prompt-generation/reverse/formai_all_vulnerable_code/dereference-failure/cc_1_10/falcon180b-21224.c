//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(*((int *) client_socket), buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            close(*((int *) client_socket));
            pthread_exit(NULL);
        }
        printf("Client %d sent: %s\n", *((int *) client_socket), buffer);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i]!= *((int *) client_socket)) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port 8080\n");

    while (1) {
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);
        client_sockets[num_clients++] = client_socket;
    }

    return 0;
}