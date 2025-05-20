//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1000

struct client {
    int socket;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    int buffer_index;
    int is_active;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;

    while (1) {
        memset(client->buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, client->buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            close(client->socket);
            client->is_active = 0;
            break;
        }

        client->buffer_index = 0;
        while (client->buffer_index < bytes_received) {
            if (client->buffer[client->buffer_index] == '\n') {
                printf("Received message: %s", client->buffer);
                client->buffer_index = 0;
            } else {
                client->buffer_index++;
            }
        }
    }

    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5000);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address));
    listen(server_socket, MAX_CLIENTS);

    printf("Server started on port 5000\n");

    while (1) {
        struct client new_client;
        socklen_t client_size = sizeof(new_client.address);
        new_client.socket = accept(server_socket, (struct sockaddr *)&new_client.address, &client_size);

        if (new_client.socket == -1) {
            printf("Error accepting client\n");
            continue;
        }

        printf("Client connected with IP address %s and port %d\n", inet_ntoa(new_client.address.sin_addr), ntohs(new_client.address.sin_port));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, &new_client);
    }

    return 0;
}