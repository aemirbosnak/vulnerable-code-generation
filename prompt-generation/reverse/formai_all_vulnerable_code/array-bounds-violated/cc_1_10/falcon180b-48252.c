//Falcon-180B DATASET v1.0 Category: System administration ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *arg) {
    int client_socket = *(int *) arg;
    char message[MAX_MESSAGE_SIZE];

    while (1) {
        memset(message, 0, MAX_MESSAGE_SIZE);
        int bytes_received = recv(client_socket, message, MAX_MESSAGE_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        message[bytes_received] = '\0';
        printf("Client %d: %s\n", client_socket, message);

        send(client_socket, message, strlen(message), 0);
    }

    close(client_socket);
    num_clients--;
}

void accept_connections() {
    struct sockaddr_in server_addr, client_addr;
    int server_socket, client_socket;
    socklen_t client_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_socket, 3);

    puts("Server is listening...");

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &client_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_socket, "Server is full. Please try again later.", strlen("Server is full. Please try again later."), 0);
            close(client_socket);
        } else {
            client_sockets[num_clients] = client_socket;
            num_clients++;

            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *) &client_socket);
        }
    }
}

int main() {
    srand(time(NULL));

    accept_connections();

    return 0;
}