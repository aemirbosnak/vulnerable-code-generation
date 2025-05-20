//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

/*
 * This program is a simple SMTP client that sends a message to a specified
 * recipient.
 */

int main(int argc, char **argv)
{
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *hostname, *message;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s hostname port recipient message\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];
    port = atoi(argv[2]);
    message = argv[4];

    /* Create a socket. */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    /* Look up the server's IP address. */
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        exit(1);
    }

    /* Fill in the server's address. */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    /* Connect to the server. */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    /* Send the HELO command. */
    if (send(sockfd, "HELO example.com\r\n", 18, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Send the MAIL FROM command. */
    if (send(sockfd, "MAIL FROM: <sender@example.com>\r\n", 33, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Send the RCPT TO command. */
    if (send(sockfd, "RCPT TO: <recipient@example.com>\r\n", 33, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Send the DATA command. */
    if (send(sockfd, "DATA\r\n", 6, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Send the message. */
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Send the dot command to indicate the end of the message. */
    if (send(sockfd, ".\r\n", 3, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Send the QUIT command. */
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0) {
        perror("send");
        exit(1);
    }

    /* Receive the server's response. */
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        exit(1);
    }

    /* Close the socket. */
    close(sockfd);

    return 0;
}