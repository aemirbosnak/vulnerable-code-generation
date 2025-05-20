//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define PORT 8888
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
int server_socket;

void *listen_thread(void *arg) {
    while (1) {
        int new_client = accept(server_socket, NULL, NULL);
        if (new_client!= -1) {
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == -1) {
                    clients[i] = new_client;
                    num_clients++;
                    break;
                }
            }
        }
    }
}

void *receive_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(clients[0], buffer, BUFFER_SIZE, 0);
        if (bytes_received > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);
            for (int i = 1; i < num_clients; i++) {
                send(clients[i], buffer, strlen(buffer), 0);
            }
        }
    }
}

void *send_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    while (1) {
        recv(clients[0], buffer, BUFFER_SIZE, 0);
        for (int i = 1; i < num_clients; i++) {
            send(clients[i], buffer, strlen(buffer), 0);
        }
    }
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    pthread_t listen_thread_id;
    pthread_t receive_thread_id;
    pthread_t send_thread_id;

    pthread_create(&listen_thread_id, NULL, &listen_thread, NULL);
    pthread_create(&receive_thread_id, NULL, &receive_thread, NULL);
    pthread_create(&send_thread_id, NULL, &send_thread, NULL);

    while (1) {
        char buffer[BUFFER_SIZE];
        printf("Enter message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        send(clients[0], buffer, strlen(buffer), 0);
    }

    return 0;
}