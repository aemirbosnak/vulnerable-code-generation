//Falcon-180B DATASET v1.0 Category: Chat server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 1000
#define MAX_MSG_SIZE 1024

struct client {
    int sock;
    char name[50];
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char msg[MAX_MSG_SIZE];

    while (1) {
        memset(msg, 0, MAX_MSG_SIZE);
        int len = recv(client->sock, msg, MAX_MSG_SIZE, 0);
        if (len <= 0) {
            close(client->sock);
            client->sock = 0;
            break;
        }

        printf("Client %s: %s\n", client->name, msg);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sock && i!= client - clients) {
                send(clients[i].sock, msg, strlen(msg), 0);
            }
        }
    }
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

    printf("Server started on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            close(client_sock);
            continue;
        }

        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sock = client_sock;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &clients[num_clients - 1]);
    }

    return 0;
}