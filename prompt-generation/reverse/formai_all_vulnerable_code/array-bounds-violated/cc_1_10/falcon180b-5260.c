//Falcon-180B DATASET v1.0 Category: Chat server ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8888
#define BACKLOG 10

// Function to print error message and exit
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to handle each client connection
void handle_client(int client_socket) {
    char buffer[1024];
    while (TRUE) {
        int bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            if (bytes_received == 0) {
                printf("Client disconnected\n");
            } else {
                printf("Error: %s\n", strerror(errno));
            }
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Received message: %s", buffer);
        send(client_socket, buffer, strlen(buffer), 0);
    }
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0)
        error("socket failed");

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    // Bind server address
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("bind failed");

    // Listen on socket
    if (listen(server_socket, BACKLOG) < 0)
        error("listen failed");

    while (TRUE) {
        // Accept client connection
        socklen_t addr_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size)) < 0)
            error("accept failed");
        printf("Client connected: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Handle client in separate thread
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, (void *)handle_client, (void *)&client_socket)!= 0)
            error("pthread_create failed");
    }

    return 0;
}