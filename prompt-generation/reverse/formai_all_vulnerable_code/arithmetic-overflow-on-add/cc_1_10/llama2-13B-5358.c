//LLAMA2-13B DATASET v1.0 Category: Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sock1, sock2;
    struct sockaddr_in server, client;
    char buffer[256];
    int bytes_received;

    // Create socket 1 (server)
    sock1 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock1 < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port number for server
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(PORT);

    // Bind socket 1 to address and port
    if (bind(sock1, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock1, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Create socket 2 (client)
    sock2 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock2 < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set address and port number for client
    client.sin_family = AF_INET;
    client.sin_addr.s_addr = INADDR_ANY;
    client.sin_port = htons(PORT);

    // Connect socket 2 to server
    if (connect(sock2, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Client connected to server...\n");

    // Send request from client to server
    send(sock2, "Hello, server!", 13, 0);

    // Receive response from server to client
    bytes_received = recv(sock1, buffer, 256, 0);
    if (bytes_received < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Received response from server: %s\n", buffer);

    // Calculate and print the average of the two numbers
    int num1 = atoi(buffer);
    int num2 = atoi(buffer + 10);
    int avg = (num1 + num2) / 2;
    printf("Average of %d and %d is %d\n", num1, num2, avg);

    // Close sockets
    close(sock1);
    close(sock2);

    return 0;
}