//Falcon-180B DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int server_socket;
int client_sockets[MAX_CLIENTS];
int client_count;

char *message = "Welcome to the server!";

void *thread_function(void *client_socket) {
    int client = *((int *) client_socket);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client, buffer);

        for (int i = 0; i < client_count; i++) {
            if (i!= client) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    close(client);
    return NULL;
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, 3);

    printf("Server is listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        client_sockets[client_count] = client_socket;
        client_count++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_function, (void *) &client_socket);
    }

    return 0;
}