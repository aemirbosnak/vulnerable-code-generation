//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024
#define THREAD_COUNT 5

struct client {
    int sock;
    char ip[16];
    int port;
};

struct client clients[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client_sock, buffer, bytes_read, 0);
    }

    close(client_sock);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_sock, THREAD_COUNT) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server started on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_len);

        if (client_count >= MAX_CLIENTS) {
            close(client_sock);
            continue;
        }

        strcpy(clients[client_count].ip, inet_ntoa(client_addr.sin_addr));
        clients[client_count].port = ntohs(client_addr.sin_port);
        clients[client_count].sock = client_sock;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sock);

        client_count++;
    }

    return 0;
}