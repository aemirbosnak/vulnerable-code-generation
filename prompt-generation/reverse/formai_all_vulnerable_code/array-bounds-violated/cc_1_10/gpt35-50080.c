//FormAI DATASET v1.0 Category: Networking ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE+1];

    // Step 1: Create a socket
    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Step 2: Bind the server socket to an address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8888);

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Step 3: Listen for incoming connections
    if (listen(server_sock, 10) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port 8888...\n");

    while (1) {
        // Step 4: Accept a connection from a client
        client_addr_size = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_addr_size);
        if (client_sock == -1) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Step 5: Receive data from the client and send response
        ssize_t bytes_received;
        while ((bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message from client: %s\n", buffer);

            if (strcmp(buffer, "Hello") == 0) {
                send(client_sock, "Hi there!", strlen("Hi there!"), 0);
            } else if (strcmp(buffer, "How are you?") == 0) {
                send(client_sock, "I'm doing well, thanks for asking.", strlen("I'm doing well, thanks for asking."), 0);
            } else {
                send(client_sock, "Sorry, I didn't understand that.", strlen("Sorry, I didn't understand that."), 0);
            }

            memset(buffer, 0, BUFFER_SIZE);
        }

        if (bytes_received == -1) {
            perror("Failed to receive message");
            exit(EXIT_FAILURE);
        }

        // Step 6: Close the client socket
        close(client_sock);
        printf("Connection closed with %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    // Step 7: Close the server socket
    close(server_sock);

    return 0;
}