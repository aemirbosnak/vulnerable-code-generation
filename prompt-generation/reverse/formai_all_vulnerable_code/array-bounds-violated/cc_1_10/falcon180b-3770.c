//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Struct to hold client socket information
typedef struct client_info {
    int sock;
    struct sockaddr_in address;
} client_info;

int main(int argc, char *argv[]) {
    int server_sock, new_sock, addrlen, client_sock[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int max_clients = 0;

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(3000);

    // Bind socket to address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 3000\n");

    while (1) {
        // Accept incoming connection
        addrlen = sizeof(client_addr);
        if ((new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        // Add new socket to client array
        for (int i = 0; i < max_clients; i++) {
            if (client_sock[i] == 0) {
                client_sock[i] = new_sock;
                break;
            }
        }
        max_clients++;

        // Send welcome message to new client
        send(new_sock, "Welcome to the server!\n", strlen("Welcome to the server!\n"), 0);
    }

    return 0;
}