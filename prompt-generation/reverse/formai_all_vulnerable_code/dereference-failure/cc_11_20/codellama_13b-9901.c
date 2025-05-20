//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
/*
 * Example POP3 client program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[256];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Check command-line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <mailbox>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Look up the server's DNS entry
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Connect to the server
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(POP3_PORT);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send the USER command
    n = write(sockfd, "USER ", 5);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, argv[2], strlen(argv[2]));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, "\r\n", 2);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server's response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the PASS command
    n = write(sockfd, "PASS ", 5);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, argv[2], strlen(argv[2]));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    n = write(sockfd, "\r\n", 2);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server's response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the LIST command
    n = write(sockfd, "LIST\r\n", 6);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server's response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the RETR command
    n = write(sockfd, "RETR 1\r\n", 7);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read the server's response
    bzero(buffer, 256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the QUIT command
    n = write(sockfd, "QUIT\r\n", 6);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}