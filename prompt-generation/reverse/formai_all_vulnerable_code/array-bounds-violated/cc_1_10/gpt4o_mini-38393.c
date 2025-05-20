//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_BUF 1024
#define MAX_CLIENTS 10

typedef struct Client {
    int socket;
    struct sockaddr_in address;
    int addr_len;
} Client;

void* handle_client(void* args);
void send_to_clients(char* message, int sender_socket);
void log_message(const char* message);

Client clients[MAX_CLIENTS];
int client_count = 0;

int main() {
    int server_socket;
    struct sockaddr_in server_address;
    char message[MAX_BUF];

    // Initialize server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Define server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Binding failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 3) < 0) {
        perror("Listening failed");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("CyberServer started on port %d...\n", PORT);
    while (1) {
        Client new_client;
        new_client.addr_len = sizeof(new_client.address);
        new_client.socket = accept(server_socket, (struct sockaddr*)&new_client.address, (socklen_t*)&new_client.addr_len);

        if (new_client.socket < 0) {
            perror("Accept failed");
            continue;
        }

        // Add the new client to the array
        if (client_count < MAX_CLIENTS) {
            clients[client_count++] = new_client;
            printf("New connection from %s:%d\n", inet_ntoa(new_client.address.sin_addr), ntohs(new_client.address.sin_port));
            pthread_t tid;
            pthread_create(&tid, NULL, handle_client, (void*)&new_client);
        } else {
            printf("Max clients reached. Connection rejected from %s:%d\n", inet_ntoa(new_client.address.sin_addr), ntohs(new_client.address.sin_port));
            close(new_client.socket);
        }
    }

    return 0;
}

void* handle_client(void* args) {
    Client client = *(Client*)args;
    char buffer[MAX_BUF];
    char user_message[MAX_BUF + 50];
    
    while (1) {
        ssize_t bytes_read = recv(client.socket, buffer, MAX_BUF, 0);
        if (bytes_read <= 0) {
            printf("Client disconnected: %s:%d\n", inet_ntoa(client.address.sin_addr), ntohs(client.address.sin_port));
            close(client.socket);
            break;
        }

        buffer[bytes_read] = '\0';
        snprintf(user_message, sizeof(user_message), "Message from %s:%d - %s", inet_ntoa(client.address.sin_addr), ntohs(client.address.sin_port), buffer);
        log_message(user_message);
        send_to_clients(user_message, client.socket);
    }

    return NULL;
}

void send_to_clients(char* message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

void log_message(const char* message) {
    FILE *log_file = fopen("cyber_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Could not open log file");
    }
}