//Falcon-180B DATASET v1.0 Category: Networking ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10

// Function for handling each client connection
void *handle_client(void *socket_desc) {
    int client_socket = *((int *) socket_desc);
    char buffer[1024];
    while(1) {
        bzero(buffer, sizeof(buffer));
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if(bytes_received <= 0) {
            printf("Client disconnected\n");
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
    return NULL;
}

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set options on the socket
    if(setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket to an address and port
    if(bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        return 1;
    }

    // Listen for incoming connections
    if(listen(server_socket, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        return 1;
    }

    while(1) {
        // Accept a new connection
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if(new_socket == -1) {
            printf("Error accepting new connection\n");
            continue;
        }

        // Create a new thread to handle the client connection
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void*)&new_socket);
    }

    close(server_socket);
    return 0;
}