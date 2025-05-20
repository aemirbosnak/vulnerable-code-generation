//Falcon-180B DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
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

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    num_clients--;
}

void accept_connections() {
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                printf("Error accepting connection: %s\n", strerror(errno));
                break;
            }
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, (const char *) &opt, sizeof(opt));

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            if (errno == EINTR) {
                continue;
            } else {
                printf("Error accepting connection: %s\n", strerror(errno));
                break;
            }
        }

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full.\n", 14, 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        }
    }

    return 0;
}