//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg);
void broadcast_message(const char *message, int sender_sock);

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    // Create socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_sock, 3);
    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept a new client
        new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sock < 0) {
            perror("Accept failed");
            continue;
        }
        
        // Lock the client list and add the new client
        pthread_mutex_lock(&clients_mutex);
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_sock;
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_sock);
            pthread_detach(tid); // Allow thread to run independently
        } else {
            printf("Max clients reached. Connection denied.\n");
            close(new_sock);
        }
        pthread_mutex_unlock(&clients_mutex);
    }

    close(server_sock);
    return 0;
}

void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate string
        printf("Received: %s", buffer); // Echo to console
        broadcast_message(buffer, sock); // Broadcast message to other clients
    }

    // Close the socket and remove the client
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == sock) {
            close(sock);
            clients[i] = clients[client_count - 1]; // Replace with last client
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_mutex);
    return NULL;
}

void broadcast_message(const char *message, int sender_sock) {
    pthread_mutex_lock(&clients_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] != sender_sock) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}