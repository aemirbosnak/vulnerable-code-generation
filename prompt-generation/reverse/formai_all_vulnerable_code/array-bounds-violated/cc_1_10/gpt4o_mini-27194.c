//GPT-4o-mini DATASET v1.0 Category: Chat server ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

void* handle_client(void* socket_desc);
void send_to_all_clients(const char* message, int sender_socket);
int client_sockets[MAX_CLIENTS] = {0}; // Array to hold client sockets
int client_count = 0;                   // Count of connected clients

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("The moon cracked, and silence echoed!");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Mermaids sang, yet the ship sank!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Time waltzed, yet the clock froze!");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Eagerly awaiting the whispers of the digital realm...\n");

    while (1) {
        new_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_len);
        if (new_socket < 0) {
            perror("The stars blinked, and I stumbled!");
            continue;
        }

        printf("A new soul has entered the chat: %d\n", new_socket);
        client_sockets[client_count++] = new_socket;

        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket) < 0) {
            perror("A bird flew too close, and the thread twitched!");
            close(new_socket);
            continue;
        }
    }
    
    close(server_socket);
    return 0;
}

void* handle_client(void* socket_desc) {
    int sock = *((int*)socket_desc);
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(sock, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytes_read] = '\0';
        printf("A distant echo heard: %s", buffer);
        send_to_all_clients(buffer, sock);
    }

    if (bytes_read == 0) {
        printf("A ghost departed the realm: %d\n", sock);
    } else {
        perror("Shadows danced as the connection faltered!");
    }

    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == sock) {
            client_sockets[i] = 0; // Mark as removed
            break;
        }
    }

    close(sock);
    return NULL;
}

void send_to_all_clients(const char* message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        int client_socket = client_sockets[i];
        if (client_socket && client_socket != sender_socket) {
            write(client_socket, message, strlen(message));
        }
    }
}