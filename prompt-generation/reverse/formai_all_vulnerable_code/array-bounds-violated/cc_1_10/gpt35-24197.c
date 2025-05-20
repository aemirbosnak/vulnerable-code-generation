//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
// This is a unique C client-server application example program.
// It implements a simple chat program where clients can connect to the server,
// send messages, and receive messages from other clients connected to the same server.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LENGTH 1000

typedef struct {
    int socket;
    struct sockaddr_in address;
    pthread_t thread;
} Client;

Client clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void send_message(char *message, int sender_socket)
{
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket != sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *handle_client(void *client_ptr)
{
    Client client = *(Client *)client_ptr;
    char message[MAX_MESSAGE_LENGTH];

    while (1) {
        int recv_size = recv(client.socket, message, sizeof(message), 0);
        if (recv_size > 0) {
            message[recv_size] = '\0';
            send_message(message, client.socket);
        } else {
            close(client.socket);
            pthread_exit(NULL);
        }
    }
}

int main(int argc, char *argv[])
{
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating server socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8888);

    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Error binding server socket\n");
        exit(EXIT_FAILURE);
    }

    listen(server_socket, 5);
    printf("Server started and listening on port 8888\n");

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);

        if (client_socket < 0) {
            printf("Error accepting client connection");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            close(client_socket);
            continue;
        }

        Client client;
        client.socket = client_socket;
        client.address = client_address;

        pthread_create(&client.thread, NULL, handle_client, &client);

        pthread_mutex_lock(&clients_mutex);
        clients[num_clients++] = client;
        pthread_mutex_unlock(&clients_mutex);

        printf("Client connected: %s:%d (total clients: %d)\n",
               inet_ntoa(client_address.sin_addr),
               ntohs(client_address.sin_port),
               num_clients);
    }

    return 0;
}