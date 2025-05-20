//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int g_server_socket;
pthread_t g_client_threads[MAX_CLIENTS];
int g_num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = 0;
        printf("Client %d: %s\n", client_socket, buffer);
    }

    close(client_socket);
    free(arg);

    return NULL;
}

void accept_connections() {
    while (g_num_clients < MAX_CLIENTS) {
        int client_socket = accept(g_server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("accept");
                exit(1);
            }
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket);
        g_client_threads[g_num_clients++] = thread_id;
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    accept_connections();

    return 0;
}