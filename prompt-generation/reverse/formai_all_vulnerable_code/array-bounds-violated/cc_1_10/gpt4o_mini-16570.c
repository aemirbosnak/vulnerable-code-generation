//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;
pthread_mutex_t client_mutex = PTHREAD_MUTEX_INITIALIZER;

void *handle_client(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Client: %s\n", buffer);
        send(sock, buffer, bytes_read, 0);
    }

    close(sock);
    pthread_exit(NULL);
}

void add_client(int sock) {
    pthread_mutex_lock(&client_mutex);
    if (client_count < MAX_CLIENTS) {
        clients[client_count++] = sock;
        printf("Client connected. Total clients: %d\n", client_count);
    } else {
        printf("Max client limit reached!\n");
    }
    pthread_mutex_unlock(&client_mutex);
}

void remove_client(int sock) {
    pthread_mutex_lock(&client_mutex);
    for (int i = 0; i < client_count; i++) {
        if (clients[i] == sock) {
            clients[i] = clients[--client_count];
            printf("Client disconnected. Total clients: %d\n", client_count);
            break;
        }
    }
    pthread_mutex_unlock(&client_mutex);
}

void *server_loop(void *arg) {
    int server_sock = *(int *)arg;
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int new_sock;

    while ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len)) >= 0) {
        add_client(new_sock);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_sock);
        pthread_detach(tid);
    }
    close(server_sock);
    pthread_exit(NULL);
}

int main() {
    int server_sock;
    struct sockaddr_in server_addr;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        return EXIT_FAILURE;
    }

    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Error listening on socket");
        return EXIT_FAILURE;
    }

    printf("Chat server started on port %d...\n", PORT);
    pthread_t server_thread;
    pthread_create(&server_thread, NULL, server_loop, &server_sock);
    pthread_detach(server_thread);

    while (1) {
        sleep(1); // Main thread keeps running
    }

    return EXIT_SUCCESS;
}