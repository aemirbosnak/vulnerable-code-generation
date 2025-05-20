//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

struct client_data {
    int sock;
    char name[20];
};

void *handle_client(void *arg) {
    struct client_data *client_data = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_data->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client %s disconnected\n", client_data->name);
            close(client_data->sock);
            free(client_data);
            break;
        }

        printf("Client %s sent: %s\n", client_data->name, buffer);
        send(client_data->sock, buffer, strlen(buffer), 0);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (1) {
        struct sockaddr_in server_addr, client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket;

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
        server_addr.sin_port = htons(8080);

        if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
            printf("Error binding socket\n");
            exit(1);
        }

        if (listen(server_socket, 10) == -1) {
            printf("Error listening on socket\n");
            exit(1);
        }

        printf("Waiting for clients...\n");

        while (num_clients < MAX_CLIENTS) {
            client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

            if (client_socket == -1) {
                printf("Error accepting client\n");
                exit(1);
            }

            printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

            struct client_data *client_data = (struct client_data *) malloc(sizeof(struct client_data));
            client_data->sock = client_socket;
            strncpy(client_data->name, inet_ntoa(client_addr.sin_addr), 20);

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) client_data);

            client_sockets[num_clients++] = client_socket;
        }
    }

    return 0;
}