//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: systematic
// Building an SMTP Client example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 25
#define MAX_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    char message[MAX_SIZE];

    if (argc < 2) {
        fprintf(stderr, "usage %s hostname\n", argv[0]);
        exit(0);
    }

    portno = PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        printf("No such host exists.\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to host.\n");
        exit(1);
    }

    // SMTP Protocol Communication

    n = read(sockfd, buffer, sizeof(buffer));
    printf("%s", buffer);

    // Send HELO message
    sprintf(message, "HELO %s\r\n", argv[1]);
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from HELO message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM:<example@mail.com>\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from MAIL FROM message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Send RCPT TO message
    sprintf(message, "RCPT TO:<recipient@mail.com>\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from RCPT TO message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from DATA message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Send message body
    sprintf(message, "From: example <example@mail.com>\r\n");
    sprintf(message, "%sTo: recipient <recipient@mail.com>\r\n", message);
    sprintf(message, "%sSubject: Test Email\r\n", message);
    sprintf(message, "%s\r\n", message);
    sprintf(message, "%sThis is a test email sent from a C program.\r\n", message);
    sprintf(message, "%s.\r\n", message);
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from sending message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) {
        printf("Error writing to socket.\n");
        exit(1);
    }

    // Receive response from QUIT message
    bzero(buffer, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}