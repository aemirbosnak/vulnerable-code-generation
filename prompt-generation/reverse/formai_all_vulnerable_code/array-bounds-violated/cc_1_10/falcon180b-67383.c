//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024
#define PORT 8080

int clients[MAX_CLIENTS][2];
int num_clients = 0;

void broadcast(int sender_socket, char* message) {
    for(int i=0; i<num_clients; i++) {
        if(clients[i][0]!= sender_socket) {
            send(clients[i][0], message, strlen(message), 0);
        }
    }
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        broadcast(client_socket, buffer);
    }
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }
    if(listen(server_socket, 3) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }
    printf("Server started on port %d\n", PORT);
    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_size);
        if(client_socket!= -1) {
            clients[num_clients][0] = client_socket;
            clients[num_clients][1] = num_clients;
            num_clients++;
            printf("Client connected: %d\n", num_clients-1);
        }
    }
    return 0;
}