//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;

void *monitor_thread(void *arg) {
    int client_socket = *((int *) arg);
    char buffer[BUFFER_SIZE];
    int bytes_received;
    struct timeval start_time, end_time;
    int latency;

    while (1) {
        gettimeofday(&start_time, NULL);
        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        gettimeofday(&end_time, NULL);

        if (bytes_received <= 0) {
            break;
        }

        latency = (end_time.tv_sec * 1000000 + end_time.tv_usec - start_time.tv_sec * 1000000 - start_time.tv_usec) / 1000;
        printf("Client %d latency: %d ms\n", client_socket, latency);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *)&server_addr, addrlen);
    listen(server_socket, MAX_CLIENTS);

    printf("Server started on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            printf("Server is full\n");
            continue;
        }

        clients[num_clients] = client_socket;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, monitor_thread, (void *)&client_socket);
    }

    return 0;
}