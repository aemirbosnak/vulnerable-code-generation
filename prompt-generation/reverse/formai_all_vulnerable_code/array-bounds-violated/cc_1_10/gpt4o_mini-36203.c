//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

void* handle_client(void* arg);
int client_count = 0;
int client_sockets[MAX_CLIENTS];

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1, addrlen = sizeof(address);
    
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("📡 Server is listening on port %d...\n", PORT);

    while ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))) {
        printf("🎉 New client connected! Socket FD: %d\n", new_socket);
        client_sockets[client_count++] = new_socket;
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, &new_socket);
    }

    return 0;
}

void* handle_client(void* arg) {
    int sock = *(int*)arg;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        printf("🗨️ Message from client %d: %s", sock, buffer);
        
        // Echoing the message back to all clients
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, read_size, 0);
            }
        }
    }

    if (read_size == 0) {
        printf("👋 Client %d disconnected!\n", sock);
        close(sock);
    } else if (read_size == -1) {
        perror("recv failed");
    }

    return NULL;
}