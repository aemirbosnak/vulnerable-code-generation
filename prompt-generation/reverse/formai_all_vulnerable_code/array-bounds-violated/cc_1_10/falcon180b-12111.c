//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket[MAX_CLIENTS], client_count = 0;
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[BUFFER_SIZE];
    int addrlen;

    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    // Listen on socket
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        // Check for new clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            addrlen = sizeof(client_addr[i]);
            client_socket[i] = accept(server_socket, (struct sockaddr *)&client_addr[i], &addrlen);

            if (client_socket[i]!= -1) {
                printf("Client connected on socket %d\n", client_socket[i]);
                client_count++;
            }
        }

        // Handle client messages
        for (int i = 0; i < client_count; i++) {
            bzero(buffer, BUFFER_SIZE);
            int bytes_received = recv(client_socket[i], buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected on socket %d\n", client_socket[i]);
                close(client_socket[i]);
                client_count--;
                break;
            }

            printf("Received message from client: %s", buffer);
        }
    }

    return 0;
}