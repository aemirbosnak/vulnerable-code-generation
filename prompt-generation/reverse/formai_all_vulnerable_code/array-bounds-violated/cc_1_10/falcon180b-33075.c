//Falcon-180B DATASET v1.0 Category: Networking ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    char hostname[50];
    int port;

    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter port number: ");
    scanf("%d", &port);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    server_addr.sin_port = htons(port);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting client\n");
            exit(1);
        }

        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Client disconnected\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        strcpy(response, "Server received your message");
        send(client_socket, response, strlen(response), 0);
    }

    close(client_socket);
}