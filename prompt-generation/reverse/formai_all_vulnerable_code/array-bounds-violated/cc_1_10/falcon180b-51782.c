//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients;
pthread_mutex_t lock;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[MAX_MSG_SIZE];

    while (1) {
        memset(buffer, 0, MAX_MSG_SIZE);
        int bytes_received = recv(client_socket, buffer, MAX_MSG_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client %d disconnected\n", client_socket);
            close(client_socket);
            pthread_mutex_lock(&lock);
            for (int i = 0; i < num_clients; i++) {
                if (client_sockets[i] == client_socket) {
                    client_sockets[i] = -1;
                    break;
                }
            }
            num_clients--;
            pthread_mutex_unlock(&lock);
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Client %d sent: %s\n", client_socket, buffer);

        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i]!= -1) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);

        pthread_mutex_lock(&lock);
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] == -1) {
                client_sockets[i] = client_socket;
                num_clients++;
                break;
            }
        }
        pthread_mutex_unlock(&lock);
    }

    return 0;
}