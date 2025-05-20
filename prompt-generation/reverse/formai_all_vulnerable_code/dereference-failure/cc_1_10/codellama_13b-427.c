//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: multiplayer
// TCP/IP Multiplayer Programming Example

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command-line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        exit(1);
    }

    // Set up server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        exit(1);
    }

    // Send message to server
    char buf[BUF_SIZE];
    fgets(buf, sizeof(buf), stdin);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send()");
        exit(1);
    }

    // Receive message from server
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv()");
        exit(1);
    }
    printf("Received message: %s\n", buf);

    // Close socket
    close(sock);

    return 0;
}