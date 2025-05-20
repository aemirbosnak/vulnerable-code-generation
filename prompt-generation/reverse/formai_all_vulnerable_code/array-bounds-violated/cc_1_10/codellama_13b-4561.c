//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: brave
// Unique C Network Topology Mapper example program in a brave style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Parse port number
    int port = atoi(argv[1]);
    if (port < 0 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Bind socket to port
    struct sockaddr_in addr;
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

    // Accept incoming connection
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept");
        return 1;
    }

    // Read client message
    char buf[1024];
    ssize_t n = recv(client_sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';

    // Print client message
    printf("Client message: %s\n", buf);

    // Send response message
    char response[] = "Hello, client!";
    n = send(client_sock, response, strlen(response), 0);
    if (n < 0) {
        perror("send");
        return 1;
    }

    // Close client socket
    close(client_sock);

    // Close server socket
    close(sock);

    return 0;
}