//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int client_sockets[MAX_CLIENTS];
char *client_names[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(char *message, int sender_socket);
void remove_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("The wasteland has swallowed the server!");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding the last remaining structures failed!");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("The call of the wild echoes, no one is left to listen!");
        exit(EXIT_FAILURE);
    }

    printf("The Last Haven Server is live on port %d. Survivors can now communicate...\n", PORT);
    
    while (client_count < MAX_CLIENTS) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("A wandering soul was lost, the connection failed!");
            continue;
        }

        pthread_mutex_lock(&clients_mutex);
        client_sockets[client_count] = client_socket;
        client_names[client_count] = malloc(30);
        snprintf(client_names[client_count], 30, "Survivor_%d", client_count + 1);
        printf("%s has joined their fate!\n", client_names[client_count]);
        client_count++;
        pthread_mutex_unlock(&clients_mutex);

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_socket) != 0) {
            perror("The thread unfurled but was lost to the shadows!");
        }
        pthread_detach(thread_id);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *arg) {
    int socket = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';  // Null terminate string
        printf("A message echoed through the wasteland: %s\n", buffer);
        broadcast_message(buffer, socket);
    }
    
    if (read_size == 0) {
        printf("A survivor has departed... connection closing.\n");
    } else {
        perror("A message was lost in the ashes of time!");
    }

    remove_client(socket);
    return NULL;
}

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            if (send(client_sockets[i], message, strlen(message), 0) < 0) {
                perror("The winds have scattered the message!");
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void remove_client(int client_socket) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == client_socket) {
            close(client_socket);
            free(client_names[i]);
            client_sockets[i] = client_sockets[client_count - 1];
            client_names[i] = client_names[client_count - 1];
            client_count--;
            printf("%s has fallen into the void...\n", client_names[i]);
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}