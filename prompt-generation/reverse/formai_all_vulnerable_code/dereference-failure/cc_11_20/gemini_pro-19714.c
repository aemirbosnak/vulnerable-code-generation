//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ctype.h>

#define PORT 25
#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    struct hostent *hp;
    char *smtp_server = "smtp.example.com";
    char *sender = "sender@example.com";
    char *recipient = "recipient@example.com";
    char *subject = "Hello from the C email client";
    char *body = "This is the body of the email.";
    char *message;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the IP address of the SMTP server
    hp = gethostbyname(smtp_server);
    if (hp == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set up the sockaddr_in struct
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    memcpy(&servaddr.sin_addr, hp->h_addr, hp->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the greeting from the SMTP server
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Send the HELO command
    snprintf(recvline, MAXLINE, "HELO %s\r\n", smtp_server);
    n = write(sockfd, recvline, strlen(recvline));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Send the MAIL FROM command
    snprintf(recvline, MAXLINE, "MAIL FROM: <%s>\r\n", sender);
    n = write(sockfd, recvline, strlen(recvline));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Send the RCPT TO command
    snprintf(recvline, MAXLINE, "RCPT TO: <%s>\r\n", recipient);
    n = write(sockfd, recvline, strlen(recvline));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Send the DATA command
    snprintf(recvline, MAXLINE, "DATA\r\n");
    n = write(sockfd, recvline, strlen(recvline));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Send the message
    message = malloc(strlen(subject) + strlen(body) + 100);
    snprintf(message, strlen(subject) + strlen(body) + 100, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", sender, recipient, subject, body);
    n = write(sockfd, message, strlen(message));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    free(message);

    // Send the QUIT command
    snprintf(recvline, MAXLINE, "QUIT\r\n");
    n = write(sockfd, recvline, strlen(recvline));
    if (n == -1) {
        perror("write");
        exit(EXIT_FAILURE);
    }
    n = read(sockfd, recvline, MAXLINE);
    if (n == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("%s", recvline);

    // Close the socket
    close(sockfd);

    return 0;
}