//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 4096

struct client {
    int sock;
    struct sockaddr_in addr;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_read = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            close(client->sock);
            free(client);
            return NULL;
        }

        send(client->sock, buffer, bytes_read, 0);
    }
}

void handle_request(int sock, struct sockaddr_in *addr) {
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_read = recv(sock, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            close(sock);
            return;
        }

        send(sock, buffer, bytes_read, 0);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        struct client *new_client = (struct client *) malloc(sizeof(struct client));
        new_client->sock = client_sock;
        new_client->addr = client_addr;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) new_client);
    }

    return 0;
}