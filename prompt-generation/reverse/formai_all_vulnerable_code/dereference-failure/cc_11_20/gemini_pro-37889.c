//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SMTP_PORT 587

int main(int argc, char *argv[])
{
    int sockfd, n;
    char buffer[1024];
    struct sockaddr_in servaddr;

    // Check for the required arguments
    if (argc < 5) {
        printf("Usage: %s <server IP> <sender email> <recipient email> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Initialize the server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read the greeting message from the server
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the EHLO command
    sprintf(buffer, "EHLO localhost\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("read");
        return 1;
    }
    printf("%s", buffer);

    // Send the email message
    sprintf(buffer, "%s\r\n.\r\n", argv[4]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
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