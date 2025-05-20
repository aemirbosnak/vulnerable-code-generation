//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the EHLO command
    char command[MAX_LINE_LENGTH];
    sprintf(command, "EHLO %s\r\n", argv[1]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    char response[MAX_LINE_LENGTH];
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Send the MAIL FROM command
    sprintf(command, "MAIL FROM:<%s>\r\n", argv[1]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Send the RCPT TO command
    sprintf(command, "RCPT TO:<%s>\r\n", argv[2]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Send the DATA command
    sprintf(command, "DATA\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Send the message body
    sprintf(command, "Subject: Hello from %s\r\n\r\nHello, %s!\r\n\r\n", argv[1], argv[2]);
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Send the QUIT command
    sprintf(command, "QUIT\r\n");
    if (send(sock, command, strlen(command), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Read the server response
    if (recv(sock, response, sizeof(response), 0) < 0) {
        perror("recv");
        exit(1);
    }
    printf("Server response: %s\n", response);

    // Close the socket
    close(sock);

    return 0;
}