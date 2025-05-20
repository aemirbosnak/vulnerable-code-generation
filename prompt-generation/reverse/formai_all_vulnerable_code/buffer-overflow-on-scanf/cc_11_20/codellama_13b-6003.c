//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
/*
 * POP3 Client in a decentralized style
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define MAX_MSG 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <server> <port>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    // Get the server address
    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *server_addr;
    int err = getaddrinfo(argv[1], argv[2], &hints, &server_addr);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(err));
        return 1;
    }

    // Connect to the server
    if (connect(sock, server_addr->ai_addr, server_addr->ai_addrlen) < 0) {
        perror("connect() failed");
        return 1;
    }

    // Read the POP3 greeting
    char buf[MAX_LINE];
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received POP3 greeting: %s\n", buf);

    // Send the USER command
    char user[MAX_LINE];
    printf("Enter your username: ");
    scanf("%s", user);
    send(sock, "USER ", 5, 0);
    send(sock, user, strlen(user), 0);
    send(sock, "\r\n", 2, 0);

    // Read the USER response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received USER response: %s\n", buf);

    // Send the PASS command
    char pass[MAX_LINE];
    printf("Enter your password: ");
    scanf("%s", pass);
    send(sock, "PASS ", 5, 0);
    send(sock, pass, strlen(pass), 0);
    send(sock, "\r\n", 2, 0);

    // Read the PASS response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received PASS response: %s\n", buf);

    // Send the STAT command
    send(sock, "STAT\r\n", 6, 0);

    // Read the STAT response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received STAT response: %s\n", buf);

    // Send the LIST command
    send(sock, "LIST\r\n", 6, 0);

    // Read the LIST response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received LIST response: %s\n", buf);

    // Send the RETR command
    int msg_num = 1;
    send(sock, "RETR ", 5, 0);
    send(sock, &msg_num, sizeof(int), 0);
    send(sock, "\r\n", 2, 0);

    // Read the RETR response
    if (recv(sock, buf, MAX_MSG, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received RETR response: %s\n", buf);

    // Send the DELE command
    send(sock, "DELE ", 5, 0);
    send(sock, &msg_num, sizeof(int), 0);
    send(sock, "\r\n", 2, 0);

    // Read the DELE response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received DELE response: %s\n", buf);

    // Send the RSET command
    send(sock, "RSET\r\n", 6, 0);

    // Read the RSET response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received RSET response: %s\n", buf);

    // Send the QUIT command
    send(sock, "QUIT\r\n", 6, 0);

    // Read the QUIT response
    if (recv(sock, buf, MAX_LINE, 0) < 0) {
        perror("recv() failed");
        return 1;
    }
    printf("Received QUIT response: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}