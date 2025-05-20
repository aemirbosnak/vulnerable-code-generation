//FormAI DATASET v1.0 Category: Client Server Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 5
#define MAX_MESSAGE_LENGTH 200

int clients[MAX_CLIENTS];
int client_count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void remove_client(int client_socket) {
    pthread_mutex_lock(&mutex);
    for(int i=0; i<client_count; i++) {
        if(clients[i] == client_socket) {
            for(int j=i; j<client_count-1; j++) {
                clients[j] = clients[j+1];
            }
            client_count--;
            break;
        }
    }
    pthread_mutex_unlock(&mutex);
}

void send_message(int sender_socket, char* message) {
    pthread_mutex_lock(&mutex);
    for(int i=0; i<client_count; i++) {
        if(clients[i] != sender_socket) {
            send(clients[i], message, strlen(message), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void* client_handler(void* socket_ptr) {
    int client_socket = *(int*)socket_ptr;
    char message[MAX_MESSAGE_LENGTH];
    while(1) {
        int message_length = recv(client_socket, message, MAX_MESSAGE_LENGTH, 0);
        if(message_length <= 0) {
            remove_client(client_socket);
            break;
        }
        message[message_length] = '\0';
        send_message(client_socket, message);
    }
    close(client_socket);
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    int client_address_length = sizeof(client_address);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error starting listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Server is running and listening on port 8080...\n");

    while(1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t*)&client_address_length);
        if(client_socket < 0) {
            perror("Error accepting a new connection");
            exit(EXIT_FAILURE);
        }
        printf("New client connected, IP address: %s, socket: %d\n", inet_ntoa(client_address.sin_addr), client_socket);
        pthread_mutex_lock(&mutex);
        if(client_count < MAX_CLIENTS) {
            clients[client_count++] = client_socket;
            pthread_t client_thread;
            if(pthread_create(&client_thread, NULL, client_handler, (void*)&client_socket) != 0) {
                perror("Error creating a new thread");
                exit(EXIT_FAILURE);
            }
        } else {
            printf("Maximum number of clients reached. Connection refused.\n");
            close(client_socket);
        }
        pthread_mutex_unlock(&mutex);
    }

    close(server_socket);
    return 0;
}