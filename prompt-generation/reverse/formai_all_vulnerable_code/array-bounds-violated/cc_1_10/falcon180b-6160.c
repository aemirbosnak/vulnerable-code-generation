//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_request(int client_socket);

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket.\n");
        close(server_socket);
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket.\n");
        close(server_socket);
        return 1;
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);

        if (client_socket == -1) {
            printf("Error accepting connection.\n");
            continue;
        }

        handle_request(client_socket);

        close(client_socket);
    }

    close(server_socket);
    return 0;
}

void handle_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

    if (bytes_received <= 0) {
        printf("Error receiving data from client.\n");
        return;
    }

    buffer[bytes_received] = '\0';
    printf("Received request: %s\n", buffer);

    char response[BUFFER_SIZE];
    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n");
    sprintf(response + strlen(response), "<html><head><title>Cyberpunk Web Server</title></head><body><h1>Welcome to the Cyberpunk Web Server!</h1></body></html>");

    send(client_socket, response, strlen(response), 0);
}