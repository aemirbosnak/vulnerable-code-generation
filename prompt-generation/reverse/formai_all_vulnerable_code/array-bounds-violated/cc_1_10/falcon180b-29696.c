//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

int clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}

void accept_connections() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port %d\n", PORT);

    while (num_clients < MAX_CLIENTS) {
        socklen_t addr_size = sizeof(struct sockaddr_in);
        int client_socket = accept(server_socket, (struct sockaddr *) &clients[num_clients], &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Client %d connected\n", client_socket);
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    accept_connections();

    return 0;
}