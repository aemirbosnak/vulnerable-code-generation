//Code Llama-13B DATASET v1.0 Category: Network Packet Monitoring ; Style: curious
// Curious C Network Packet Monitoring Program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int sock, n;
    char buffer[1024];
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Setup the server address
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(atoi(argv[1]));

    // Bind the socket to the address
    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Waiting for incoming connections...\n");

    // Accept incoming connections
    if ((n = accept(sock, (struct sockaddr *)&client, &client_len)) < 0) {
        perror("accept failed");
        exit(1);
    }

    // Read the incoming packet
    while ((n = read(n, buffer, 1024)) > 0) {
        printf("Packet received: %s\n", buffer);
    }

    // Close the socket
    close(sock);

    return 0;
}