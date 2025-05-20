//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAX_CLIENTS 10

int server_socket;
int client_sockets[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received;
    
    while (1) {
        bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message from client: %s\n", buffer);
        
        if (strcmp(buffer, "exit") == 0) {
            break;
        }
        
        send(client_socket, buffer, strlen(buffer), 0);
    }
    
    close(client_socket);
    num_clients--;
}

void handle_signal(int sig) {
    for (int i = 0; i < num_clients; i++) {
        close(client_sockets[i]);
    }
    close(server_socket);
    exit(0);
}

int main() {
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    int client_socket;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating server socket");
        exit(1);
    }
    
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5000);
    server_address.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }
    
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Error listening on server socket");
        exit(1);
    }
    
    signal(SIGINT, handle_signal);
    
    while (1) {
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_len);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }
        
        if (num_clients >= MAX_CLIENTS) {
            close(client_socket);
            continue;
        }
        
        client_sockets[num_clients] = client_socket;
        num_clients++;
        
        handle_client(client_socket);
    }
    
    close(server_socket);
    
    return 0;
}