//Falcon-180B DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_NAME_LEN 64
#define MAX_NUMBER_LEN 16

typedef struct client {
    int sock;
    char name[MAX_NAME_LEN];
    char number[MAX_NUMBER_LEN];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_sock = *(int *) arg;
    char buffer[1024];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recv(client_sock, buffer, sizeof(buffer), 0);

        char *name = strtok(buffer, ":");
        char *number = strtok(NULL, ":");

        strcpy(clients[num_clients].name, name);
        strcpy(clients[num_clients].number, number);

        num_clients++;

        close(client_sock);
        break;
    }

    pthread_exit(0);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    while (1) {
        int client_sock = accept(server_sock, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full\n", sizeof("Server is full\n"), 0);
            close(client_sock);
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_sock);
    }

    return 0;
}