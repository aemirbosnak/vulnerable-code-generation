//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_socket[MAX_CLIENTS];
int num_clients;

void *receive_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    int client_index;

    client_index = (int)arg;

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        recv(client_socket[client_index], buffer, BUFFER_SIZE, 0);

        printf("Received message from client %d: %s\n", client_index, buffer);
        send(client_socket[client_index], "ACK", 3, 0);
    }

    return NULL;
}

void *send_thread(void *arg) {
    char buffer[BUFFER_SIZE];
    int client_index;

    client_index = (int)arg;

    while (1) {
        printf("Enter message for client %d: ", client_index);
        fgets(buffer, BUFFER_SIZE, stdin);
        bzero(buffer, BUFFER_SIZE);

        send(client_socket[client_index], buffer, BUFFER_SIZE, 0);
    }

    return NULL;
}

int main() {
    int yes = 1;
    int port = 8080;
    int client_index;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to port");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening");
        exit(1);
    }

    num_clients = 0;

    while (yes == 1) {
        client_index = num_clients;
        num_clients++;

        if (num_clients >= MAX_CLIENTS) {
            fprintf(stderr, "Maximum number of clients reached\n");
            break;
        }

        client_socket[client_index] = accept(server_socket, NULL, NULL);

        if (client_socket[client_index] == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("New client connected\n");

        pthread_t thread1, thread2;

        if (pthread_create(&thread1, NULL, receive_thread, (void*)&client_index)!= 0) {
            perror("Error creating receive thread");
            exit(1);
        }

        if (pthread_create(&thread2, NULL, send_thread, (void*)&client_index)!= 0) {
            perror("Error creating send thread");
            exit(1);
        }

        if (pthread_join(thread1, NULL)!= 0) {
            perror("Error joining receive thread");
            exit(1);
        }

        if (pthread_join(thread2, NULL)!= 0) {
            perror("Error joining send thread");
            exit(1);
        }

        close(client_socket[client_index]);
    }

    return 0;
}