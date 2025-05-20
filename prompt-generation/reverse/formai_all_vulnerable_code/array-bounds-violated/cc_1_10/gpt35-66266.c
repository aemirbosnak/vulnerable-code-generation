//FormAI DATASET v1.0 Category: Firewall ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_sock, client_sock;
    socklen_t sin_size;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create socket");
        exit(1);
    }

    // Configure server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    memset(&(server_addr.sin_zero), '\0', 8);

    // Bind socket to address and port
    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) == -1) {
        perror("Failed to bind socket");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) == -1) {
        perror("Failed to listen for connections");
        exit(1);
    }

    printf("Server is listening for connections...\n");

    while (1) {
        sin_size = sizeof(struct sockaddr_in);

        // Accept incoming connection
        if ((client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &sin_size)) == -1) {
            perror("Failed to accept connection");
            continue;
        }

        printf("Accepted new connection from %s\n", inet_ntoa(client_addr.sin_addr));

        // Read data from client
        int bytes_received = recv(client_sock, buffer, BUFFER_SIZE, 0);
        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        // Close connection
        close(client_sock);
        printf("Closed connection from %s\n\n", inet_ntoa(client_addr.sin_addr));
    }

    // Close socket
    close(server_sock);

    return 0;
}