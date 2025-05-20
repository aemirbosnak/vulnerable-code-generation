//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 2048
#define NAME_SIZE 32

typedef struct {
    int socket;
    char name[NAME_SIZE];
} Client;

void handle_client(Client *client) {
    char buffer[BUFFER_SIZE];
    int read_size;

    while ((read_size = recv(client->socket, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[read_size] = '\0';
        printf("[%s]: %s\n", client->name, buffer);

        // Echo back to the client
        send(client->socket, buffer, read_size, 0);  
    }

    if (read_size == 0) {
        printf("[%s] disconnected\n", client->name);
    } else {
        perror("recv failed");
    }

    close(client->socket);
    free(client);
}

void *client_handler(void *arg) {
    Client *client = (Client *) arg;
    handle_client(client);
    return NULL;
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind
    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        close(server_socket);
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        close(server_socket);
        return EXIT_FAILURE;
    }

    printf("Neon-lit server listening on port %d...\n", PORT);

    // Accept clients
    while (1) {
        Client *client = (Client *) malloc(sizeof(Client));
        if (!client) {
            perror("malloc");
            continue;
        }
        
        client_socket = accept(server_socket, (struct sockaddr *) &client_addr, &addr_len);
        if (client_socket < 0) {
            perror("accept");
            free(client);
            continue;
        }

        // Retrieve the client name
        printf("Incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
        printf("Enter your name: ");
        fgets(client->name, NAME_SIZE, stdin);
        client->name[strcspn(client->name, "\n")] = 0; // strip newline
        
        client->socket = client_socket;

        // Create a thread for the new client
        if (pthread_create(&tid, NULL, client_handler, (void *) client) != 0) {
            perror("pthread_create");
            close(client_socket);
            free(client);
        }

        pthread_detach(tid);  // Automatically clean up when the thread terminates
    }

    close(server_socket);
    return 0;
}