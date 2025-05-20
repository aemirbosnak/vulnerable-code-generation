//Falcon-180B DATASET v1.0 Category: Firewall ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void process_connection(int client_socket);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        int client_socket;
        struct sockaddr_in client_addr;
        socklen_t client_addr_size;

        if ((client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_size)) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        process_connection(client_socket);
    }

    return 0;
}

void process_connection(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        if ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) == -1) {
            printf("Error receiving data\n");
            break;
        }

        if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        if (strcmp(buffer, "quit") == 0) {
            break;
        }
    }

    close(client_socket);
}