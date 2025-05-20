//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUF_SIZE 1024
#define MAX_CLIENTS 100

int client_sockets[MAX_CLIENTS];
static int client_count = 0;

void *handle_client(void *socket_desc);
void send_message_to_all_clients(char *message, int sender_socket);
void remove_client(int socket);

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Creating socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Configuring server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Binding
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Chat server started on port %d. Waiting for clients...\n", PORT);

    while (1) {
        // Accepting new connections
        if ((new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len)) < 0) {
            perror("Accept failed");
            continue;
        }

        // Adding new client
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = new_socket;

            // Creating thread for each client
            pthread_t client_thread;
            if (pthread_create(&client_thread, NULL, handle_client, (void *)&new_socket) != 0) {
                perror("Thread creation failed");
            }
        } else {
            printf("Maximum clients connected. Rejecting client.\n");
            close(new_socket);
        }
    }

    return 0;
}

void *handle_client(void *socket_desc) {
    int sock = *(int *)socket_desc;
    char buffer[BUF_SIZE];
    int len;

    while ((len = recv(sock, buffer, sizeof(buffer)-1, 0)) > 0) {
        buffer[len] = '\0'; // Null-terminate the string
        printf("Client %d: %s\n", sock, buffer);
        send_message_to_all_clients(buffer, sock);
    }

    if (len == 0) {
        printf("Client %d disconnected.\n", sock);
    } else {
        perror("Recv failed");
    }

    close(sock);
    remove_client(sock);

    return NULL;
}

void send_message_to_all_clients(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) { // Don't send to the sender
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void remove_client(int socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[client_count - 1]; // Replace with last socket
            client_count--; // Reduce client count
            break;
        }
    }
}