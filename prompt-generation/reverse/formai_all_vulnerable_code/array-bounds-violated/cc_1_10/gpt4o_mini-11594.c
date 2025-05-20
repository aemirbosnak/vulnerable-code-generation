//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

void* handle_client(void* args);
void broadcast_message(char* message, int sender_socket);
void error(const char *msg);

int client_sockets[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    
    // Creating socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) 
        error("ERROR opening socket");

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR on binding");

    // Start listening
    listen(server_socket, 3);
    printf("🎉 Chat server started on port %d! Ready to rock and roll! 🎸\n", PORT);

    while (1) {
        // Accepting a new client connection
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (client_socket < 0) 
            error("ERROR on accept");

        // Adding client socket to the array
        if (client_count < MAX_CLIENTS) {
            client_sockets[client_count++] = client_socket;
            printf("🧑‍🤝‍🧑 New friend joined us, total buddies: %d\n", client_count);

            // Create new thread for handling client
            pthread_t thread_id;
            if (pthread_create(&thread_id, NULL, handle_client, (void*)&client_socket) != 0) {
                perror("Failed to create thread 😱");
            }
        } else {
            printf("☠️ Too many friends! Rejecting the new buddy 😢\n");
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}

void* handle_client(void* args) {
    int client_socket = *(int*)args;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate the string
        printf("🗨️ Message from a cool buddy: %s\n", buffer);
        broadcast_message(buffer, client_socket);
    }

    if (bytes_received == 0) {
        printf("👋 A buddy disconnected. Bye bye!\n");
    } else if (bytes_received < 0) {
        perror("recv failed 🙈");
    }

    close(client_socket);
    return NULL;
}

void broadcast_message(char* message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        // Send message to all sockets except the sender
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}