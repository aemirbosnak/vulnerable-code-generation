//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define NUM_THREADS 5

int clients[MAX_CLIENTS];
int num_clients = 0;

int thread_id[NUM_THREADS];
pthread_t thread[NUM_THREADS];

int start_server(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        close(server_socket);
        return -1;
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        close(server_socket);
        return -1;
    }

    printf("Server started on port %d\n", port);
    return server_socket;
}

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d sent message: %s\n", client_socket, buffer);
    }

    close(client_socket);
    return NULL;
}

int main(int argc, char **argv) {
    srand(time(NULL));
    int server_socket = start_server(PORT);

    while (num_clients < MAX_CLIENTS) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket!= -1) {
            int thread_id = rand() % NUM_THREADS;
            clients[num_clients++] = client_socket;
            pthread_create(&thread[thread_id], NULL, handle_client, (void *)&client_socket);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(thread[i], NULL);
    }

    close(server_socket);
    return 0;
}