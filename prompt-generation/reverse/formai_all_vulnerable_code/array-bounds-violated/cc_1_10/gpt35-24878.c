//FormAI DATASET v1.0 Category: Chat server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

int clients[MAX_CLIENTS];
int num_clients = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int client_fd = *(int *) arg;
    char buffer[1024];
    int read_size;

    puts("Client connected.");

    while ((read_size = recv(client_fd, buffer, 1024, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received message from client: %s\n", buffer);

        pthread_mutex_lock(&mutex);

        for (int i = 0; i < num_clients; i++) {
            if (clients[i] != client_fd) {
                if (write(clients[i], buffer, strlen(buffer)) != strlen(buffer)) {
                    perror("Write error");
                    break;
                }
            }
        }

        pthread_mutex_unlock(&mutex);
    }

    if (read_size == 0) {
        puts("Client disconnected.");
    } else if (read_size == -1) {
        perror("Recv error");
    }

    close(client_fd);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 5) == -1) {
        perror("Listen error");
        exit(EXIT_FAILURE);
    }

    puts("Server initialized. Waiting for clients...");

    while (1) {
        socklen_t client_len = sizeof(client_addr);
        client_fd = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
        if (client_fd == -1) {
            perror("Accept error");
            continue;
        }

        if (num_clients >= MAX_CLIENTS) {
            puts("Max number of clients reached.");
            close(client_fd);
            continue;
        }

        pthread_mutex_lock(&mutex);

        clients[num_clients++] = client_fd;

        pthread_mutex_unlock(&mutex);

        if (pthread_create(&thread_id, NULL, handle_client, (void *) &client_fd) != 0) {
            perror("Thread creation error");
            break;
        }

        pthread_detach(thread_id);
    }

    close(server_fd);
    pthread_mutex_destroy(&mutex);
    return 0;
}