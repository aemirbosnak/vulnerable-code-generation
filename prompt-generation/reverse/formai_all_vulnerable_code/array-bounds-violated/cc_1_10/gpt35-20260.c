//FormAI DATASET v1.0 Category: Client Server Application ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int server_socket, client_socket;
struct sockaddr_in server_address, client_address;

void* handle_client(void* arg) {
    int client_socket = *((int*)arg);
    char buffer[BUFFER_SIZE];

    while (1) {
        int length = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (length <= 0) {
            close(client_socket);
            return NULL;
        }
        buffer[length] = '\0';
        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, length, 0);
    }
}

int main() {
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Failed to create server socket\n");
        return -1;
    }
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        printf("Failed to bind server socket\n");
        return -1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Failed to listen on server socket\n");
        return -1;
    }
    printf("Server is listening on port %d\n", PORT);

    while (1) {
        socklen_t client_address_size = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_size);
        if (client_socket == -1) {
            printf("Failed to accept client connection\n");
            continue;
        }
        printf("Accepted a client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, &client_socket) == -1) {
            printf("Failed to create client handling thread\n");
            continue;
        }
    }
    close(server_socket);
    return 0;
}