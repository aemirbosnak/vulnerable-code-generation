//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void *handle_client(void *socket_desc);
void broadcast_message(char *message, int sender_socket);

int client_sockets[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons(PORT);
    
    // Binding the socket to the specified port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    while (1) {
        // Accepting new client connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        pthread_mutex_lock(&mutex);
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;
            pthread_t thread_id;
            pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket);
        } else {
            printf("Max client limit reached. Connection refused for socket %d\n", new_socket);
            close(new_socket);
        }
        pthread_mutex_unlock(&mutex);
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client [%d]: %s\n", sock, buffer);
        broadcast_message(buffer, sock);
    }

    // Remove the client from the list and free the socket
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count];
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
    close(sock);
    return 0;
}

void broadcast_message(char *message, int sender_socket) {
    pthread_mutex_lock(&mutex);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}