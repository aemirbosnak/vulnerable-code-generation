//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 100

static int client_count = 0;
static struct sockaddr_in clients[MAX_CLIENTS];

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

static void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[1024];

    while (1) {
        bzero(buffer, sizeof(buffer));
        if (recv(client_socket, buffer, sizeof(buffer), 0) <= 0) {
            pthread_mutex_lock(&mutex);
            client_count--;
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].sin_addr.s_addr == clients[client_socket].sin_addr.s_addr && clients[i].sin_port == clients[client_socket].sin_port) {
                    clients[i] = clients[MAX_CLIENTS - 1];
                    break;
                }
            }
            pthread_mutex_unlock(&mutex);
            break;
        }

        printf("Received message from client: %s\n", buffer);

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sin_addr.s_addr != 0 && clients[i].sin_port != 0 && clients[i].sin_addr.s_addr != clients[client_socket].sin_addr.s_addr && clients[i].sin_port != clients[client_socket].sin_port) {
                send(clients[i].sin_addr.s_addr, buffer, sizeof(buffer), 0);
            }
        }
    }

    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_length;
    pthread_t thread;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_address_length = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_length);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        pthread_mutex_lock(&mutex);
        clients[client_count] = client_address;
        client_count++;
        pthread_mutex_unlock(&mutex);

        if (pthread_create(&thread, NULL, handle_client, &client_socket) != 0) {
            perror("pthread_create");
            close(client_socket);
            continue;
        }
    }

    close(server_socket);
    return 0;
}