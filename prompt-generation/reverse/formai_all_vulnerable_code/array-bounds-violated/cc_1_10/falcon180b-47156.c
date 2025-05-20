//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[MAX_REQUEST_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, MAX_REQUEST_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d says: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Server is running on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        if ((new_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addrlen)) == -1) {
            perror("accept");
            exit(1);
        }

        clients[num_clients] = new_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &new_socket);
    }

    close(server_socket);
    return 0;
}