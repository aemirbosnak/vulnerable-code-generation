//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
// POP3 client example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define POP3_PORT 110
#define MAX_MESSAGES 10
#define MAX_MESSAGE_SIZE 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // Connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send POP3 greeting
    char buffer[MAX_MESSAGE_SIZE];
    int n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received greeting: %s\n", buffer);

    // Send USER command
    char command[MAX_MESSAGE_SIZE];
    sprintf(command, "USER %s\r\n", argv[2]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive USER response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received USER response: %s\n", buffer);

    // Send PASS command
    sprintf(command, "PASS %s\r\n", argv[3]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive PASS response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received PASS response: %s\n", buffer);

    // Send STAT command
    sprintf(command, "STAT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive STAT response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received STAT response: %s\n", buffer);

    // Send LIST command
    sprintf(command, "LIST\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive LIST response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received LIST response: %s\n", buffer);

    // Send RETR command
    sprintf(command, "RETR 1\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive RETR response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received RETR response: %s\n", buffer);

    // Send DELE command
    sprintf(command, "DELE 1\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive DELE response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received DELE response: %s\n", buffer);

    // Send QUIT command
    sprintf(command, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive QUIT response
    n = read(sock, buffer, MAX_MESSAGE_SIZE);
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("Received QUIT response: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}