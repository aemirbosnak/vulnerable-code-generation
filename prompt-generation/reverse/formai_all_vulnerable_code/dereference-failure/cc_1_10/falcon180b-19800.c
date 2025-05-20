//Falcon-180B DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

typedef struct client_info {
    int sock;
    char *name;
    struct client_info *next;
} client_info;

client_info *clients = NULL;

void *thread_func(void *arg) {
    client_info *client = arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_read = recv(client->sock, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            break;
        }
        printf("%s says: %s\n", client->name, buffer);
        send(client->sock, buffer, bytes_read, 0);
    }

    close(client->sock);
    free(client->name);
    free(client);

    return NULL;
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_sock, BACKLOG);

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        client_info *client = malloc(sizeof(client_info));
        client->sock = accept(server_sock, NULL, NULL);
        printf("Client connected\n");

        char name[20];
        bzero(name, 20);
        recv(client->sock, name, 20, 0);
        client->name = strdup(name);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, client);
    }

    return 0;
}