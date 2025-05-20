//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: curious
// A curious TCP/IP Programming example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Set the address and port for the server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[1]));
    addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the address to the socket
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(sock, 3) == -1) {
        perror("listen");
        return 1;
    }

    // Accept an incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock == -1) {
        perror("accept");
        return 1;
    }

    // Read and print the message from the client
    char buffer[1024];
    int n = read(client_sock, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        return 1;
    }
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(client_sock);
    close(sock);

    return 0;
}