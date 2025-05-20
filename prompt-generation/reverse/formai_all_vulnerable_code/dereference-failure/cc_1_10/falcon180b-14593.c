//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 4096

struct client_info {
    int sockfd;
    struct sockaddr_in server_addr;
};

void *handle_client(void *arg) {
    struct client_info *client_info = arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        ssize_t bytes_received = recv(client_info->sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_info->sockfd);
            break;
        }

        send(client_info->sockfd, buffer, bytes_received, 0);
    }

    return NULL;
}

int main() {
    int listen_sockfd, accept_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;

    listen_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sockfd == -1) {
        printf("Error creating listen socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding listen socket\n");
        exit(1);
    }

    if (listen(listen_sockfd, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        accept_sockfd = accept(listen_sockfd, (struct sockaddr *)&client_addr, NULL);
        if (accept_sockfd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        struct client_info *client_info = malloc(sizeof(struct client_info));
        client_info->sockfd = accept_sockfd;
        memcpy(&client_info->server_addr, &server_addr, sizeof(server_addr));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client_info);
    }

    return 0;
}