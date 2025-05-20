//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int server_socket;
int client_sockets[MAX_CLIENTS];
socklen_t client_addr_size;
struct sockaddr_in server_addr, client_addr;
char buffer[BUFFER_SIZE];

void init_server() {
    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    // Bind socket to port 8080 and set to listen mode
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);
    bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);
}

void handle_client(int client_index) {
    printf("Handling client %d\n", client_index);
    int n;
    
    // Receive message from client
    n = recv(client_sockets[client_index], buffer, BUFFER_SIZE, 0);
    buffer[n] = '\0';
    printf("Received message: %s\n", buffer);
    
    // Send response to client
    char response[BUFFER_SIZE];
    strcpy(response, "Hello, ");
    strcat(response, buffer);
    send(client_sockets[client_index], response, strlen(response), 0);
}

void accept_clients() {
    printf("Waiting for clients...\n");
    client_addr_size = sizeof(client_addr);
    for(int i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size);
        printf("Client %d connected\n", i);
        handle_client(i);
        close(client_sockets[i]);
        printf("Client %d disconnected\n", i);
    }
}

int main() {
    // Initialize server
    init_server();
    
    // Accept client connections and handle messages
    accept_clients();
    
    return 0;
}