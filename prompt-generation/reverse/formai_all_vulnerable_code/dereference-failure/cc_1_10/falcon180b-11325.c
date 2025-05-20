//Falcon-180B DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define MAX_CLIENTS 10

int g_server_socket;
pthread_t g_client_threads[MAX_CLIENTS];
int g_num_clients;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUF_SIZE];

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent message: %s\n", client_socket, buffer);

        for (int i = 0; i < g_num_clients; i++) {
            if (i!= client_socket) {
                send(g_client_threads[i], buffer, bytes_received, 0);
            }
        }
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(3000);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Server started on port 3000\n");

    g_server_socket = server_socket;
    g_num_clients = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            printf("Error accepting socket: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected on socket %d\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &client_socket);

        g_client_threads[g_num_clients++] = thread_id;
    }

    return 0;
}