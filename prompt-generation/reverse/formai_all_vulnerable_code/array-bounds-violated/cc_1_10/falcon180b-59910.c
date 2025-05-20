//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    while (1) {
        addrlen = sizeof(struct sockaddr_in);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Client connected\n");

        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes = 0;

    while ((bytes_received = recv(client_socket, buffer + total_bytes, BUFFER_SIZE - total_bytes, 0)) > 0) {
        total_bytes += bytes_received;
        buffer[total_bytes] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(client_socket);
}