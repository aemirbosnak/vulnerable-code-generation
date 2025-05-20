//Falcon-180B DATASET v1.0 Category: Networking ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

int listening_socket;
int client_sockets[MAX_CLIENTS];
int client_socket_count = 0;

sem_t mutex;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        printf("Client %d sent: %s\n", client_socket, buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    close(client_socket);
    sem_post(&mutex);

    return NULL;
}

void accept_connections() {
    while (1) {
        sem_wait(&mutex);

        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        client_socket_count++;
        if (client_socket_count >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        client_sockets[client_socket_count] = client_socket;
        printf("Client %d connected\n", client_socket);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
    }
}

int main() {
    int listening_socket_fd;
    struct sockaddr_in server_addr;

    listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listening_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listening_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    sem_init(&mutex, 0, 1);

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, accept_connections, NULL);

    return 0;
}