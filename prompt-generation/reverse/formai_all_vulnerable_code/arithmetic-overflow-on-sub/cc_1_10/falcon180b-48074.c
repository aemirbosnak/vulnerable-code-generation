//Falcon-180B DATASET v1.0 Category: Weather simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct client_info {
    int sockfd;
    struct sockaddr_in address;
    char name[20];
} client_info;

client_info clients[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("%s: %s\n", clients[client_socket - 3].name, buffer);
        for (int i = 0; i < num_clients; i++) {
            if (i!= client_socket - 3) {
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5000);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
    listen(server_socket, MAX_CLIENTS);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (num_clients >= MAX_CLIENTS) {
            printf("Server is full\n");
            close(client_socket);
            continue;
        }
        printf("New client connected\n");
        getpeername(client_socket, (struct sockaddr *) &clients[num_clients].address, sizeof(clients[num_clients].address));
        inet_ntop(AF_INET, &clients[num_clients].address.sin_addr, clients[num_clients].name, sizeof(clients[num_clients].name));
        clients[num_clients].sockfd = client_socket;
        num_clients++;
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }

    return 0;
}