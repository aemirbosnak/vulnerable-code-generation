//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 256

int clients[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *arg) {
    int sock = *((int *)arg);
    char buffer[BUFFER_SIZE];
    
    while (1) {
        int read_size = recv(sock, buffer, BUFFER_SIZE, 0);
        if (read_size <= 0) {
            close(sock);
            return NULL;
        }
        buffer[read_size] = '\0';

        // Broadcast message to all clients
        for (int i = 0; i < client_count; i++) {
            if (clients[i] != sock) {
                send(clients[i], buffer, read_size, 0);
            }
        }
    }
}

int main() {
    int server_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    
    // Bind socket
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(server_sock, 3);

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (new_sock < 0) {
            perror("Connection failed");
            continue;
        }

        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_sock;
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void *)&new_sock);
            printf("Client connected: %d\n", new_sock);
        } else {
            printf("Max clients connected. Client rejected: %d\n", new_sock);
            close(new_sock);
        }
    }

    close(server_sock);
    return 0;
}