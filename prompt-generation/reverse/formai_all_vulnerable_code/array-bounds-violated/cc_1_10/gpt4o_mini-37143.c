//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 256
#define MAX_CLIENTS 10

int client_count = 0;
int client_sockets[MAX_CLIENTS];

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[read_size] = '\0';  // Null-terminate the received string

        // Broadcast the message to all connected clients
        for (int i = 0; i < client_count; i++) {
            if (client_sockets[i] != sock) {
                send(client_sockets[i], buffer, strlen(buffer), 0);
            }
        }
    }
    
    // Remove client socket from the list
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            for (int j = i; j < client_count - 1; j++) {
                client_sockets[j] = client_sockets[j + 1];
            }
            client_count--;
            break;
        }
    }
    
    close(sock);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int sockfd, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Creating socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Listening for clients
    if (listen(sockfd, 3) < 0) {
        perror("Listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        // Accepting a new client
        if ((new_socket = accept(sockfd, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        printf("New client connected\n");

        // Store new socket in array
        client_sockets[client_count++] = new_socket;

        // Spawn a thread to handle the client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&new_socket) < 0) {
            perror("Could not create thread");
            close(new_socket);
        }
    }

    close(sockfd);
    return 0;
}