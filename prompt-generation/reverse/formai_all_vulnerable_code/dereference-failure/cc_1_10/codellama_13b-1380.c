//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: careful
/*
 * Building a POP3 Client
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define POP3_TIMEOUT 30

int main(int argc, char **argv) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket()");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        perror("inet_pton()");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect()");
        return 1;
    }

    // Send the username
    char *username = argv[2];
    if (send(sock, username, strlen(username), 0) < 0) {
        perror("send()");
        return 1;
    }

    // Receive the response
    char response[1024];
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv()");
        return 1;
    }

    // Print the response
    printf("Server response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}