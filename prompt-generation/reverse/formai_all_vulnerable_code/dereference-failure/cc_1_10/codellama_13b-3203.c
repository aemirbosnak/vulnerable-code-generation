//Code Llama-13B DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int sock;
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);
    char buffer[256];

    if (argc < 3) {
        printf("Usage: %s <server_ip> <port>\n", argv[0]);
        return 1;
    }

    // Create a UDP socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    // Set up the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_port = htons(atoi(argv[2]));

    // Bind the socket to the server address
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        return 1;
    }

    // Accept an incoming connection
    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        return 1;
    }

    // Receive the message from the client
    if (recv(client_sock, buffer, 255, 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Print the received message
    printf("Received: %s\n", buffer);

    // Send a message back to the client
    if (send(client_sock, "Hello, client!", 13, 0) < 0) {
        perror("send failed");
        return 1;
    }

    // Close the socket
    close(client_sock);

    return 0;
}