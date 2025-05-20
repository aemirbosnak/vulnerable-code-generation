//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 25
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        fprintf(stderr, "Invalid server address: %s\n", argv[1]);
        return 1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the message
    char *message = argv[2];
    if (send(sock, message, strlen(message), 0) == -1) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}