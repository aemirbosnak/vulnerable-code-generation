//FormAI DATASET v1.0 Category: Networking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char message[BUF_SIZE] = "Hello from the server!";

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    // Bind the socket to a specific IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8080);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(server_sock, 5) < 0) {
        perror("listen failed");
        return EXIT_FAILURE;
    }

    printf("Server is listening on port 8080...\n");

    // Accept incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
        perror("accept failed");
        return EXIT_FAILURE;
    }
    printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

    // Receive message from client
    int recv_bytes = recv(client_sock, buffer, BUF_SIZE, 0);
    if (recv_bytes == 0) {
        printf("Client disconnected\n");
    } else if (recv_bytes < 0) {
        perror("recv failed");
        return EXIT_FAILURE;
    } else {
        buffer[recv_bytes] = '\0';
        printf("Received message from client: %s\n", buffer);

        // Send message to client
        printf("Sending message to client: %s\n", message);
        if (send(client_sock, message, strlen(message), 0) < 0) {
            perror("send failed");
            return EXIT_FAILURE;
        }
    }

    // Close sockets
    close(client_sock);
    close(server_sock);

    return EXIT_SUCCESS;
}