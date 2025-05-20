//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <recipient> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname("smtp.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Connect to the SMTP server
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SMTP_PORT);
    serveraddr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read the SMTP server's welcome message
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", "localhost");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the HELO command
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the MAIL FROM command
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", argv[1]);
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the RCPT TO command
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the DATA command
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the message body
    if (write(sockfd, argv[2], strlen(argv[2])) < 0) {
        perror("write");
        return 1;
    }

    // Send the CRLF terminator
    if (write(sockfd, "\r\n", 2) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the message body
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write");
        return 1;
    }

    // Read the SMTP server's response to the QUIT command
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}