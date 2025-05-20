//GPT-4o-mini DATASET v1.0 Category: Networking ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 256

void *handle_client(void *client_socket);
void send_message_to_all_clients(char *message, int sender_socket);
int client_sockets[MAX_CLIENTS];
int client_count = 0;

void cosmic(void) {
    printf("Welcome to the Galactic Chatroom!\n");
    printf("A place where thoughts and stars collide...\n");
    printf("Prepare for an interstellar journey through messages!\n\n");
}

int main() {
    cosmic();

    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Starship could not be launched (socket creation failed)");
        exit(EXIT_FAILURE);
    }

    // Prepare the stardust for binding
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Asteroid field ahead! (binding failed)");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Black hole detected! (listen failed)");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("The server is now a lighthouse in the void, awaiting connections...\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_socket < 0) {
            perror("An alien signal interrupted the connection!");
            continue;
        }

        if (client_count >= MAX_CLIENTS) {
            printf("The cosmos is full! Connection denied.\n");
            close(client_socket);
            continue;
        }

        client_sockets[client_count++] = client_socket;
        printf("A new traveler has joined our realms...\n");

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, (void *)&client_socket);
        pthread_detach(thread);
    }

    close(server_socket);
    return 0;
}

void *handle_client(void *client_socket) {
    int socket = *(int *)client_socket;
    char message[BUFFER_SIZE];
    char welcome_msg[BUFFER_SIZE];

    sprintf(welcome_msg, "Greetings, Traveler! You have entered the cosmic chatroom!");
    send(socket, welcome_msg, strlen(welcome_msg), 0);

    while (1) {
        int bytes_received = recv(socket, message, sizeof(message) - 1, 0);
        if (bytes_received <= 0) {
            printf("A star has fallen. Connection closed...\n");
            break;
        }

        message[bytes_received] = '\0';
        printf("Message from a traveler: %s\n", message);
        send_message_to_all_clients(message, socket);
    }

    close(socket);
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] == socket) {
            client_sockets[i] = client_sockets[--client_count];  // Remove socket from array
            break;
        }
    }
    return NULL;
}

void send_message_to_all_clients(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (client_sockets[i] != sender_socket) {
            send(client_sockets[i], message, strlen(message), 0);
        }
    }
}