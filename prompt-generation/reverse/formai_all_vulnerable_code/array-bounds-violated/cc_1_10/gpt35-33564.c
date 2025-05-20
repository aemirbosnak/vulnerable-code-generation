//FormAI DATASET v1.0 Category: Simple Web Server ; Style: decentralized
/*
* C Simple Web Server Example Program
* This program creates a decentralized network of servers 
* that are able to communicate with each other and 
* serve HTTP requests from clients.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 30
#define PORT 8888
#define MAX_BUFFER_SIZE 1024

void *handle_client(void *arg);

typedef struct {
    int index;
    int socket;
    struct sockaddr_in address;
} client_t;

client_t clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(int argc, char *argv[]) {
    int server_socket, client_socket, opt = 1;
    struct sockaddr_in server_address, client_address;

    // Create Server Socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket Creation Error");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("Socket Options Error");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_address, '0', sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind Server Address to Socket
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Socket Binding Error");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen Error");
        exit(EXIT_FAILURE);
    }

    int address_len = sizeof(client_address);

    // Accept incoming connections
    while ((client_socket = accept(server_socket, (struct sockaddr *) &client_address,
                                    (socklen_t *) &address_len))) {
        // Lock the mutex before modifying the clients array
        pthread_mutex_lock(&mutex);
        int i;
        for (i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].socket == 0) {
                clients[i].index = i;
                clients[i].socket = client_socket;
                clients[i].address = client_address;
                pthread_t thread;
                if (pthread_create(&thread, NULL, handle_client, (void *) (long) i) < 0) {
                    perror("Thread Creation Error");
                    exit(EXIT_FAILURE);
                }
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
        if (i == MAX_CLIENTS) {
            fprintf(stderr, "Maximum Clients Reached\n");
            close(client_socket);
        }
    }

    return 0;
}

void *handle_client(void * arg) {
    int index = (int) (long) arg;
    client_t client = clients[index];
    int received_len;
    char message_buffer[MAX_BUFFER_SIZE] = {0};
    while ((received_len = recv(client.socket, message_buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        message_buffer[received_len] = '\0';
        printf("Received Message: %s\n", message_buffer);
        send(client.socket, message_buffer, strlen(message_buffer), 0);
    }
    pthread_mutex_lock(&mutex);
    close(client.socket);
    clients[index].socket = 0;
    pthread_mutex_unlock(&mutex);
    return NULL;
}