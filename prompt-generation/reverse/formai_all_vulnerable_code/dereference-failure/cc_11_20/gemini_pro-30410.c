//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) != 1) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buf[1024];
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the USER response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[2]);
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the PASS response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LIST response
    if (recv(sock, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the list of messages
    char *ptr = buf;
    while (*ptr != '\0') {
        char *end = strchr(ptr, '\n');
        if (end != NULL) {
            *end = '\0';
        }
        printf("%s\n", ptr);
        ptr = end + 1;
    }

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}