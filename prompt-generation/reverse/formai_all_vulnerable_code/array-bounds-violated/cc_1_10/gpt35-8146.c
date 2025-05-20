//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 500

int client_count = 0;
int clients[MAX_CLIENTS];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void broadcast(char *msg, int sender_fd) {
    int i;
    pthread_mutex_lock(&mutex);
    for(i = 0; i < client_count; i++) {
        if(clients[i] != sender_fd) {
            send(clients[i], msg, strlen(msg), 0);
        }
    }
    pthread_mutex_unlock(&mutex);
}

void *handle_client(void *args) {
    int client_fd = *(int*)args;
    char msg[MAX_MSG_LEN];
    char name[20];
    int read_len;

    // Get client name
    read_len = recv(client_fd, name, 20, 0);
    name[read_len-1] = '\0';

    // Send welcome message to client
    sprintf(msg, "Welcome %s!\n", name);
    send(client_fd, msg, strlen(msg), 0);

    // Broadcast new user to all clients
    sprintf(msg, "%s has joined the chat\n", name);
    broadcast(msg, client_fd);

    while(1) {
        read_len = recv(client_fd, msg, MAX_MSG_LEN, 0);
        if(read_len <= 0) {
            break;
        }
        msg[read_len] = '\0';
        sprintf(msg, "%s: %s", name, msg);
        broadcast(msg, client_fd);
    }

    // Client disconnected
    sprintf(msg, "%s has left the chat\n", name);
    broadcast(msg, client_fd);
    close(client_fd);
    pthread_exit(NULL);
}

int main() {
    int server_fd, client_fd, port;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == 0) {
        printf("Could not create socket\n");
        exit(1);
    }

    // Bind socket to port 8080
    port = 8080;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if(bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Could not bind socket to port %d\n", port);
        exit(1);
    }

    // Listen for incoming connections
    if(listen(server_fd, 5) < 0) {
        printf("Could not listen\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", port);

    // Accept incoming connections and handle them in separate threads
    while(1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if(client_fd < 0) {
            printf("Error accepting connection\n");
            continue;
        }

        if(client_count == MAX_CLIENTS) {
            printf("Max clients reached\n");
            continue;
        }

        clients[client_count++] = client_fd;

        pthread_create(&tid, NULL, handle_client, (void*)&client_fd);
    }

    return 0;
}