//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

struct client {
    int sock;
    struct sockaddr_in addr;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        send(client->sock, buffer, bytes_received, 0);
    }

    close(client->sock);
    free(client);

    return NULL;
}

int main() {
    int listen_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    listen(listen_sock, 5);

    while (1) {
        socklen_t addr_size = sizeof(client_addr);
        new_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_size);

        struct client *client = (struct client *) malloc(sizeof(struct client));
        client->sock = new_sock;
        client->addr = client_addr;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client);
    }

    return 0;
}