//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in address;
} client_t;

void* handle_client(void* arg) {
    client_t* client = (client_t*)arg;
    char buffer[BUFFER_SIZE];
    int recv_bytes;

    // Receive statistics from client
    recv_bytes = recv(client->sockfd, buffer, sizeof(buffer), 0);
    if (recv_bytes <= 0) {
        perror("recv failed");
        close(client->sockfd);
        free(client);
        return NULL;
    }

    buffer[recv_bytes] = '\0'; // null-terminate the string

    // Process the received statistics
    printf("Received statistics from client: %s\n", buffer);
    
    // Responding with a simple acknowledgment message
    char response[BUFFER_SIZE];
    snprintf(response, sizeof(response), "Statistics received: \"%s\"", buffer);

    send(client->sockfd, response, strlen(response), 0);
    
    close(client->sockfd);
    free(client);
    
    return NULL;
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t thread_id;

    // Create server socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        close(server_sock);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new client connection
        client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);
        if (client_sock < 0) {
            perror("Accept failed");
            continue; // continue to next iteration if accept fails
        }

        // Allocate memory for client structure
        client_t* client = malloc(sizeof(client_t));
        if (!client) {
            perror("Failed to allocate memory for client");
            close(client_sock);
            continue; // skip this client if malloc failed
        }

        client->sockfd = client_sock;
        client->address = client_addr;

        // Create a new thread for the client
        if (pthread_create(&thread_id, NULL, handle_client, client) != 0) {
            perror("Thread creation failed");
            close(client_sock);
            free(client);
            continue; // skip to next iteration in case of thread creation failure
        }

        // Detach the thread so it cleans up after itself
        pthread_detach(thread_id);
    }

    close(server_sock);
    return 0;
}