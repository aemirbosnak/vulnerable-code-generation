//GPT-4o-mini DATASET v1.0 Category: Socket programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Structure to hold client information
typedef struct {
    int socket;
    struct sockaddr_in addr;
    char name[30];
} Client;

Client clients[MAX_CLIENTS];
int client_count = 0;

// Function to send a message to all clients
void broadcast_message(char *message, int sender_socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket != sender_socket) {
            send(clients[i].socket, message, strlen(message), 0);
        }
    }
}

// Function to add a new client
void add_client(int new_socket, struct sockaddr_in address) {
    if (client_count < MAX_CLIENTS) {
        clients[client_count].socket = new_socket;
        clients[client_count].addr = address;
        snprintf(clients[client_count].name, sizeof(clients[client_count].name), "Client %d", client_count + 1);
        client_count++;
        printf("%s has connected. Total clients: %d\n", clients[client_count - 1].name, client_count);
    } else {
        printf("Max client limit reached. Connection rejected.\n");
        close(new_socket);
    }
}

// Function to remove a client
void remove_client(int socket) {
    for (int i = 0; i < client_count; i++) {
        if (clients[i].socket == socket) {
            printf("%s has disconnected.\n", clients[i].name);
            close(clients[i].socket);
            clients[i] = clients[client_count - 1];
            client_count--;
            break;
        }
    }
}

// Main function with futuristic socket server
int main() {
    int server_socket, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];
    
    // Creating socket file descriptor
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Attaching socket to the port
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Setting up the address structure
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listening for connections
    if (listen(server_socket, 3) < 0) {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    printf("Futuristic Socket Server Initialized. Awaiting connections...\n");

    while (1) {
        // Accepting new client connection
        if ((new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept");
            continue;
        }

        add_client(new_socket, address);

        // Create a new thread for each client to handle communication
        if (fork() == 0) { // Child process
            while (1) {
                ssize_t bytes_read = recv(new_socket, buffer, sizeof(buffer) - 1, 0);
                if (bytes_read <= 0) { // client disconnects
                    remove_client(new_socket);
                    exit(0);
                }
                buffer[bytes_read] = '\0'; // Null terminate the string
                printf("%s: %s\n", clients[client_count - 1].name, buffer);
                broadcast_message(buffer, new_socket); // Broadcast to other clients
            }
        }
    }

    // Clean up and close server socket
    close(server_socket);
    return 0;
}