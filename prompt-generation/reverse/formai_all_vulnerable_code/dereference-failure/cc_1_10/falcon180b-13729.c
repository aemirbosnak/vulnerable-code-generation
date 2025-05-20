//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

typedef struct {
    int sock;
    char ip[16];
    int port;
} client_t;

void *thread_routine(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[1024];
    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        int len = recv(client->sock, buffer, sizeof(buffer), 0);
        if (len <= 0) {
            break;
        }
        printf("[%s:%d] %s\n", client->ip, client->port, buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket error\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("bind error\n");
        return 2;
    }

    if (listen(sock, BACKLOG) == -1) {
        printf("listen error\n");
        return 3;
    }

    while (TRUE) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *) &client_addr, &addr_size);
        if (client_sock == -1) {
            printf("accept error\n");
            continue;
        }

        client_t *client = (client_t *) malloc(sizeof(client_t));
        strcpy(client->ip, inet_ntoa(client_addr.sin_addr));
        client->port = ntohs(client_addr.sin_port);
        client->sock = client_sock;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_routine, (void *) client);
    }

    close(sock);
    return 0;
}