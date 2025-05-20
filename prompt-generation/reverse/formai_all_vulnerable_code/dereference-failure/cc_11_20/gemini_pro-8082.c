//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <smtp-server> <from> <to>\n", argv[0]);
        exit(1);
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        exit(1);
    }

    // Resolve the SMTP server's address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "gethostbyname: %s\n", argv[1]);
        exit(1);
    }

    // Fill in the server's address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    memcpy(&servaddr.sin_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        exit(1);
    }

    // Read the welcome message
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: %s\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the email body
    char *body = "Hello, world!\n";
    n = write(sockfd, body, strlen(body));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Send the end-of-data marker
    sprintf(buffer, ".\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n == -1)
    {
        perror("write");
        exit(1);
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n == -1)
    {
        perror("read");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}