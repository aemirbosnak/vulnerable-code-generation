//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: calm
// A SMTP client example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define constants
#define SMTP_PORT 25
#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc < 2) {
        printf("Usage: %s <server_ip> <from_address> <to_address> <message>\n", argv[0]);
        return 1;
    }

    // Get server IP and message
    char *server_ip = argv[1];
    char *from_address = argv[2];
    char *to_address = argv[3];
    char *message = argv[4];

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    // Setup socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the message to the server
    char buf[MAX_BUF_SIZE];
    sprintf(buf, "HELO %s\r\n", from_address);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message to the server
    sprintf(buf, "MAIL FROM: <%s>\r\n", from_address);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message to the server
    sprintf(buf, "RCPT TO: <%s>\r\n", to_address);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message to the server
    sprintf(buf, "DATA\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message to the server
    sprintf(buf, "%s\r\n.\r\n", message);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message to the server
    sprintf(buf, "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Wait for the server's response
    if (recv(sock, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sock);

    return 0;
}