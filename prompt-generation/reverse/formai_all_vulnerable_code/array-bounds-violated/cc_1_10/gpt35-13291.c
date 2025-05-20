//FormAI DATASET v1.0 Category: Networking ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *client_handler(void *client_socket) {
    int socket_fd = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %d: %s\n", socket_fd, buffer);
        pthread_mutex_lock(&client_mutex);
        for (int i = 0; i < client_count; i++) {
            send(clients[i], buffer, strlen(buffer), 0);
        }
        pthread_mutex_unlock(&client_mutex);
        memset(buffer, 0, BUFFER_SIZE);
    }

    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == socket_fd) {
            while (i++ < client_count-1) {
                clients[i] = clients[i+1];
            }
            break;
        }
    }
    client_count--;
    pthread_mutex_unlock(&client_mutex);
    close(socket_fd);
    pthread_exit(NULL);
}

int main(int argc, char const *argv[]) {
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size = sizeof(server_addr);

    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&server_addr, 0, addr_size);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_addr, addr_size) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Listening on port 8080...\n");

    while (1) {
        // accept new connection
        int client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            perror("accept failed");
            continue;
        }

        // add client to list
        pthread_mutex_lock(&client_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count] = client_socket;
            client_count++;
            pthread_t tid;
            pthread_create(&tid, NULL, client_handler, &clients[client_count-1]);
        }
        pthread_mutex_unlock(&client_mutex);
    }

    // close server socket
    close(server_socket);
    return 0;
}