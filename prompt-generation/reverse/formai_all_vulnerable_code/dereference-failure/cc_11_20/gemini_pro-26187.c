//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFSIZE 1024

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <server> <port> <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Resolve the server's address
    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: Could not resolve server address\n");
        return EXIT_FAILURE;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    serveraddr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        fprintf(stderr, "Error: Could not connect to server\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the HELO command
    char buffer[BUFFSIZE];
    snprintf(buffer, BUFFSIZE, "HELO %s\r\n", argv[0]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Could not send HELO command\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    snprintf(buffer, BUFFSIZE, "MAIL FROM:<%s>\r\n", argv[3]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Could not send MAIL FROM command\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    snprintf(buffer, BUFFSIZE, "RCPT TO:<%s>\r\n", argv[4]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Could not send RCPT TO command\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the DATA command
    snprintf(buffer, BUFFSIZE, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Could not send DATA command\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the message
    snprintf(buffer, BUFFSIZE, "%s\r\n.\r\n", argv[5]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Error: Could not send message\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, BUFFSIZE, 0) < 0) {
        fprintf(stderr, "Error: Could not receive server's response\n");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}