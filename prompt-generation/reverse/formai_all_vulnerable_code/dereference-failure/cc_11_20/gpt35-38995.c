//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NO 25 // SMTP default port
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, n;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    if (argc != 2) {
        fprintf(stderr,"Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    port = PORT_NO;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr,"ERROR: Couldn't open socket\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR: Couldn't find host %s\n", argv[1]);
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        fprintf(stderr,"ERROR: Couldn't connect to host %s on port %d\n", argv[1], port);
        exit(1);
    }

    // Read the server's initial response message
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    // Connect to the SMTP server
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's response message to HELO command
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // Send the sender's email address to the SMTP server
    sprintf(buffer, "MAIL FROM:<%s>\r\n", "sender@example.com");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's response message to MAIL FROM command
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // Send the recipient's email address to the SMTP server
    sprintf(buffer, "RCPT TO:<%s>\r\n", "recipient@example.com");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's response message to RCPT TO command
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // Send the email content to the SMTP server
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's response message to DATA command
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // Send the email subject and body to the SMTP server
    sprintf(buffer, "Subject: This is a test email\r\n\r\nThis is a test email from the SMTP client example program\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's response message to the email content
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    // End the session and close the socket
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't write to socket\n");
        exit(1);
    }

    // Read the server's final response message
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) {
        fprintf(stderr,"ERROR: Couldn't read from socket\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);

    return 0;
}