//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: Claude Shannon
// Shannon's Socket Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check for input arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Get the port number
    int port = atoi(argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the socket options
    int opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // Bind the socket
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen");
        return 1;
    }

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Receive data from the client
    char buffer[1024];
    int bytes_received = recv(client_sock, buffer, 1024, 0);
    if (bytes_received < 0) {
        perror("recv");
        return 1;
    }

    // Print the received data
    printf("Received %d bytes from client %s\n", bytes_received, inet_ntoa(client_addr.sin_addr));
    printf("Data: %s\n", buffer);

    // Send data to the client
    char *message = "Hello, client!";
    if (send(client_sock, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the connection
    close(client_sock);

    return 0;
}