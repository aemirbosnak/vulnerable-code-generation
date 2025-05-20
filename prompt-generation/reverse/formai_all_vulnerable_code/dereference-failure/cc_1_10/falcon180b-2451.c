//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

struct client {
    int socket;
    char username[20];
};

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    struct client *client = (struct client *) client_socket;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s sent message: %s\n", client->username, buffer);

        send(client->socket, buffer, strlen(buffer), 0);
    }

    close(client->socket);
    free(client);

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, BACKLOG);

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        struct client *new_client = (struct client *) malloc(sizeof(struct client));
        new_client->socket = client_socket;

        printf("New client connected\n");

        char username[20];
        send(client_socket, "Enter your username: ", strlen("Enter your username: "), 0);
        recv(client_socket, username, 20, 0);

        strcpy(new_client->username, username);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) new_client);
    }

    return 0;
}