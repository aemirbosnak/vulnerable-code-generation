//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct Client {
    int socket;
    struct sockaddr_in address;
};

struct Client clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_lock;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_index);
void add_client(int client_socket, struct sockaddr_in client_addr);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);
    pthread_mutex_init(&client_lock, NULL);

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("New connection established: socket %d\n", new_socket);
        add_client(new_socket, client_addr);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_count) != 0) {
            perror("Thread creation failed");
            close(new_socket);
        } else {
            pthread_detach(thread_id);
        }
    }

    close(server_socket);
    return 0;
}

void add_client(int client_socket, struct sockaddr_in client_addr) {
    pthread_mutex_lock(&client_lock);
    if (client_count < MAX_CLIENTS) {
        clients[client_count].socket = client_socket;
        clients[client_count].address = client_addr;
        client_count++;
    } else {
        printf("Maximum clients reached. Connection rejected: socket %d\n", client_socket);
        close(client_socket);
    }
    pthread_mutex_unlock(&client_lock);
}

void broadcast_message(char *message, int sender_index) {
    pthread_mutex_lock(&client_lock);
    for (int i = 0; i < client_count; i++) {
        if (i != sender_index) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&client_lock);
}

void *handle_client(void *arg) {
    int index = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while (1) {
        bytes_read = recv(clients[index].socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_read <= 0) {
            printf("Client disconnected: socket %d\n", clients[index].socket);
            close(clients[index].socket);
            break;
        }
        buffer[bytes_read] = '\0';
        printf("Message from client %d: %s\n", clients[index].socket, buffer);
        broadcast_message(buffer, index);
    }

    pthread_mutex_lock(&client_lock);
    for (int i = index; i < client_count - 1; i++) {
        clients[i] = clients[i + 1];
    }
    client_count--;
    pthread_mutex_unlock(&client_lock);
    return NULL;
}