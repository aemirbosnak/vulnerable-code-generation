//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8888
#define MAX_BUFFER_SIZE 256

int main()
{
    int sock_fd, new_sock_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[MAX_BUFFER_SIZE];
    int bytes_recv, bytes_sent;

    // Create a TCP socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    // Start listening on the socket
    if (listen(sock_fd, 5) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    printf("Server waiting for client connections...\n");

    while (1) {
        // Accept incoming client connections
        client_addr_len = sizeof(client_addr);
        new_sock_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sock_fd == -1) {
            perror("Error accepting client connection");
            exit(1);
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // Receive data from the client
        bytes_recv = recv(new_sock_fd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_recv == -1) {
            perror("Error receiving data");
            exit(1);
        }
        buffer[bytes_recv] = '\0';
        printf("Received %d bytes from client: %s\n", bytes_recv, buffer);

        // Send data back to the client
        bytes_sent = send(new_sock_fd, buffer, strlen(buffer), 0);
        if (bytes_sent == -1) {
            perror("Error sending data");
            exit(1);
        }
        printf("Sent %d bytes back to client\n", bytes_sent);

        // Close the connection with the client
        close(new_sock_fd);
        printf("Connection closed with client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    }

    // Close the listening socket
    close(sock_fd);

    return 0;
}