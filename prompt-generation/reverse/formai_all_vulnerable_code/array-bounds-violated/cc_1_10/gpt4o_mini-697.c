//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];

void *handle_client(void *arg) {
    int client_socket = *(int *)arg;
    char buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0'; // Null-terminate the received message
        printf("Client: %s", buffer);

        // Echo back to the client
        send(client_socket, buffer, bytes_read, 0);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    int opt = 1;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the specified port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Prepare to listen for clients
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d...\n", PORT);

    int client_count = 0;
    pthread_t client_threads[MAX_CLIENTS];

    while (client_count < MAX_CLIENTS) {
        // Accept a new client connection
        if ((new_client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }
        
        printf("New connection: socket fd is %d, ip is: %s, port: %d\n",
               new_client_socket, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        client_sockets[client_count] = new_client_socket;
        
        if (pthread_create(&client_threads[client_count], NULL, handle_client, &client_sockets[client_count]) != 0) {
            perror("Failed to create thread");
            close(new_client_socket);
        } else {
            client_count++;
        }
    }

    // Cleanup
    for (int i = 0; i < client_count; i++) {
        pthread_join(client_threads[i], NULL);
    }
    
    close(server_socket);
    return 0;
}