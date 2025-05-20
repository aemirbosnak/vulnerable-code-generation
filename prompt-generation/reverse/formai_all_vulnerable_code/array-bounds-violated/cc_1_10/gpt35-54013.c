//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 4096

void *handle_client(void *arg);

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addrlen;

    // Create server socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to IP and port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket to IP and port");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on 0.0.0.0:8000\n");

    while (1) {
        // Accept incoming connection
        client_addrlen = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &client_addrlen);
        if (client_sock < 0) {
            perror("Failed to accept incoming connection");
            exit(EXIT_FAILURE);
        }

        // Spawn new thread to handle client
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)&client_sock) < 0) {
            perror("Failed to create thread");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

void *handle_client(void *arg) {
    int client_sock = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    printf("New client connected\n");

    // Read data from client
    while ((read_size = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("Received: %s", buffer);

        // Echo data back to client
        if (send(client_sock, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to client");
            exit(EXIT_FAILURE);
        }
    }

    if (read_size == 0) {
        printf("Client disconnected\n");
    } else if (read_size < 0) {
        perror("Failed to receive data from client");
    }

    close(client_sock);
    pthread_exit(NULL);
}