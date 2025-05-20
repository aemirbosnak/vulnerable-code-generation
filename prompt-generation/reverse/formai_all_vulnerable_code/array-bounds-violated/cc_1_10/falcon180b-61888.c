//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080
#define SERVER_IP "127.0.0.1"

void *handle_request(void *arg) {
    int client_socket = *(int *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        // Send response to client
        send(client_socket, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 0\r\n\r\n", 73, 0);
    }

    close(client_socket);
    return NULL;
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 2;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        return 3;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_request, (void *) &client_socket);
    }

    return 0;
}