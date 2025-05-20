//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define POOL_SIZE 10

struct client_data {
    int sock;
    char ip[16];
    char username[64];
    char password[64];
};

void *handle_client(void *arg) {
    struct client_data *data = (struct client_data *) arg;
    char buf[BUF_SIZE];
    int n;

    while ((n = recv(data->sock, buf, BUF_SIZE, 0)) > 0) {
        buf[n] = '\0';
        printf("Received: %s\n", buf);
    }

    if (n == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Error: %s\n", strerror(errno));
    }

    close(data->sock);
    free(data);

    return NULL;
}

void accept_connections(int server_sock) {
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int client_sock;

    while (1) {
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_len);

        if (client_sock == -1) {
            printf("Error: %s\n", strerror(errno));
            continue;
        }

        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        struct client_data *data = (struct client_data *) malloc(sizeof(struct client_data));
        data->sock = client_sock;
        inet_ntop(AF_INET, &client_addr.sin_addr, data->ip, sizeof(data->ip));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, data);
    }
}

int main() {
    int server_sock, opt = 1;
    struct sockaddr_in server_addr;

    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(110);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(server_sock, POOL_SIZE) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("POP3 server started on port 110\n");

    accept_connections(server_sock);

    return 0;
}