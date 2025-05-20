//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25 // SMTP Port Number
#define MAXSIZE 1024 // Maximum buffer size

int main(){
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAXSIZE];
    char message[MAXSIZE];

    printf("Enter server name: ");
    fgets(buffer, MAXSIZE, stdin);
    server = gethostbyname(buffer);

    if (server == NULL) {
        fprintf(stderr, "Error: No such host.\n");
        exit(0);
    }

    portno = PORT; // SMTP Port Number

    // Creating a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: Could not create socket.\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(portno);

    // Connecting to the SMTP Server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error: Could not connect to SMTP Server.\n");
        exit(0);
    }

    printf("\nConnected to SMTP Server...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the HELO command
    sprintf(message, "HELO %s\r\n", "example.com");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent HELO command...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the MAIL FROM command
    sprintf(message, "MAIL FROM:<%s>\r\n", "example@example.com");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent MAIL FROM command...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the RCPT TO command
    sprintf(message, "RCPT TO:<%s>\r\n", "recipient@example.com");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent RCPT TO command...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the DATA command
    sprintf(message, "DATA\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent DATA command...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the message
    sprintf(message, "From: <%s>\nTo: <%s>\nSubject: %s\n\nThis is the body of the email.\r\n.\r\n", "example@example.com", "recipient@example.com", "Test Email");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent message...\n");

    // Reading the response from the SMTP Server
    bzero(buffer, MAXSIZE);
    n = read(sockfd, buffer, MAXSIZE);
    if (n < 0) {
        fprintf(stderr, "Error: Could not read from socket.\n");
        exit(0);
    }
    printf("%s", buffer);

    // Sending the QUIT command
    sprintf(message, "QUIT\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        fprintf(stderr, "Error: Could not write to socket.\n");
        exit(0);
    }

    printf("\nSent QUIT command...\n");

    // Closing the socket
    close(sockfd);

    printf("\nDisconnected from SMTP Server...\n");

    return 0;
}