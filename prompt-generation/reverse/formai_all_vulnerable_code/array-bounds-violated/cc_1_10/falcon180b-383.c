//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUF_SIZE 1024

int listen_socket;
int client_socket;

void *handle_client(void *arg) {
    char buffer[BUF_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUF_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in server_addr, client_addr;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, (socklen_t *)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client connected with IP: %s and port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
    }

    return 0;
}