//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PROXY_PORT 8080
#define PROXY_IP "127.0.0.1"

struct client {
    int sock;
    char ip[16];
    int port;
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
}

int main() {
    int server_sock, client_sock, opt = 1;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
    struct client *client;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PROXY_PORT);
    server_addr.sin_addr.s_addr = inet_addr(PROXY_IP);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, sizeof(client_addr))) == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        client = (struct client *) malloc(sizeof(struct client));
        strcpy(client->ip, inet_ntoa(client_addr.sin_addr));
        client->port = ntohs(client_addr.sin_port);
        client->sock = client_sock;

        if (pthread_create(&thread_id, NULL, handle_client, client)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    return 0;
}