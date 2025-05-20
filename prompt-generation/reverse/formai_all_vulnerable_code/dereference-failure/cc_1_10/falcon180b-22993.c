//Falcon-180B DATASET v1.0 Category: Networking ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/types.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %d sent: %s\n", client_socket, buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

// Server function to listen for incoming connections
void server() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }
    printf("Server listening on port %d\n", PORT);
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        printf("Client %d connected\n", client_socket);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void *) handle_client, (void *) &client_socket);
    }
    close(server_socket);
}

int main() {
    server();
    return 0;
}