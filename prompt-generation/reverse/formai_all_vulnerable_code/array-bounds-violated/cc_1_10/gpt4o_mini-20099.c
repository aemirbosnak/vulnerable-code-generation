//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0'; // Null-terminate the received string
        printf("Client %d: %s", sock, buffer);
        
        // Send message to all clients
        for (int i = 0; i < num_clients; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }

    // Remove socket when client disconnects
    close(sock);
    for (int i = 0; i < num_clients; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[num_clients-1];
            num_clients--;
            break;
        }
    }
    return 0;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accept new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("accept");
            continue;
        }

        // Add new client to the list
        if (num_clients < MAX_CLIENTS) {
            client_sockets[num_clients++] = new_socket;
            printf("New client connected: %d\n", new_socket);

            // Spawn a new thread to handle client
            pthread_t client_thread;
            if (pthread_create(&client_thread, NULL, handle_client, (void *)&new_socket) < 0) {
                perror("pthread_create");
            }
        } else {
            printf("Max clients connected. Connection refused for: %d\n", new_socket);
            close(new_socket);
        }
    }

    close(server_fd);
    return 0;
}