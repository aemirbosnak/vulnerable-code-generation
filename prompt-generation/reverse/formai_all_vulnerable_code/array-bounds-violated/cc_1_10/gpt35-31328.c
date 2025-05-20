//FormAI DATASET v1.0 Category: Networking ; Style: multi-threaded
//This is a multi-threaded server program that accepts client connections and echos back any messages sent by clients to all the other connected clients using threads

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUF_SIZE 1024

int client_sockets[MAX_CLIENTS];
pthread_t threads[MAX_CLIENTS];
pthread_mutex_t mutex;

void remove_client(int i) {
    close(client_sockets[i]);
    pthread_mutex_lock(&mutex);
    for(int j = i; j < MAX_CLIENTS - 1; j++)
        client_sockets[j] = client_sockets[j+1];
    pthread_mutex_unlock(&mutex);
}

void *handle_client(void *arg) {
    int current_client = *(int*)arg;
    char buf[BUF_SIZE];
    int bytes;
    while((bytes = recv(client_sockets[current_client], buf, BUF_SIZE, 0)) > 0) {
        buf[bytes] = '\0';
        pthread_mutex_lock(&mutex);
        for(int i = 0; i < MAX_CLIENTS; i++) {
            if(i != current_client) {
                send(client_sockets[i], buf, bytes, 0);
            }
        }
        pthread_mutex_unlock(&mutex);
    }
    remove_client(current_client);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        perror("Could not create server socket");
        exit(1);
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(4000);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Could not bind server socket");
        exit(1);
    }
    if(listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Could not listen on server socket");
        exit(1);
    }

    printf("Server listening on port 4000...\n");

    int num_clients = 0;
    pthread_mutex_init(&mutex, NULL);
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if(client_socket == -1) {
            perror("Could not accept client connection");
            continue;
        }
        pthread_mutex_lock(&mutex);
        client_sockets[num_clients++] = client_socket;
        pthread_mutex_unlock(&mutex);
        pthread_create(&threads[num_clients-1], NULL, handle_client, &num_clients-1);
    }

    close(server_socket);
    return 0;
}