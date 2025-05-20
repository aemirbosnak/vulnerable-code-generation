//Falcon-180B DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int clients[MAX_CLIENTS];
int num_clients = 0;
int server_socket;

void *handle_client(void *client_socket) {
    char buffer[BUFFER_SIZE];
    int client_socket_copy = *((int *) client_socket);

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(client_socket_copy, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client_socket_copy, buffer);
        send(client_socket_copy, buffer, strlen(buffer), 0);
    }

    close(client_socket_copy);
    num_clients--;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket < 0) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &clients[num_clients - 1]);
    }

    close(server_socket);
    return 0;
}