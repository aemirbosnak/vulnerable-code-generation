//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080

// Function to print error message and exit
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[1024];
    while (1) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
        send(client_socket, "ACK", strlen("ACK"), 0);
    }
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        error("socket failed");
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind socket
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("bind failed");
    }

    // Listen on socket
    if (listen(server_socket, 10) == -1) {
        error("listen failed");
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        // Accept client connection
        socklen_t addr_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) == -1) {
            error("accept failed");
        }

        printf("Client connected with IP %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Spawn a new thread to handle client requests
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void*)handle_client, (void*)client_socket);
    }

    return 0;
}