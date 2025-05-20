//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: careful
/*
 * A simple TCP/IP programming example in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Check if the number of arguments is correct
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Set the address of the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    char message[] = "Hello, World!";
    if (send(sock, message, strlen(message), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive a message from the server
    char buffer[1024];
    if (recv(sock, buffer, 1024, 0) < 0) {
        perror("recv");
        return 1;
    }
    printf("Received: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}