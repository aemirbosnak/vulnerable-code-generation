//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int client_sockets[MAX_CLIENTS];
int client_count = 0;

void *handle_client(void *socket_desc);
void send_message_to_all(char *message, int sender_socket);

int main() {
    int server_socket, client_socket, addr_len;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed.");
        exit(EXIT_FAILURE);
    }

    // Set up the address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed.");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed.");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("🦜 Welcome to the Pirate Chat Room! 🏴‍☠️\n");

    while (1) {
        addr_len = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addr_len)) < 0) {
            perror("Accepting connection failed.");
            continue;
        }

        printf("🗣️ A new pirate has joined the chat!\n");

        // Add client socket to list
        client_sockets[client_count++] = client_socket;

        // Create a thread for the new client
        pthread_t client_thread;
        if (pthread_create(&client_thread, NULL, handle_client, (void*)&client_socket) != 0) {
            perror("Failed to create thread.");
            close(client_socket);
            continue;
        }
    }
    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int*)socket_desc;
    char message[BUFFER_SIZE];

    while (1) {
        int received = recv(sock, message, sizeof(message), 0);
        if (received <= 0) {
            break; // Client has disconnected
        }

        message[received] = '\0'; // NULL terminate the string
        printf("🏴‍☠️ A pirate shouts: %s\n", message);
        send_message_to_all(message, sock);
    }

    // Remove client socket from list
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = client_sockets[--client_count];
            break;
        }
    }
    close(sock);
    printf("💔 A pirate has left the chat!\n");
    return NULL;
}

void send_message_to_all(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}