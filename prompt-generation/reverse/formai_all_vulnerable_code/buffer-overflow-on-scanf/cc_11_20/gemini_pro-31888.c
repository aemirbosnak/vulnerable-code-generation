//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define SMTP_PORT 25

int main()
{
    // Get the hostname of the SMTP server
    char hostname[1024];
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);

    // Get the port number of the SMTP server
    int port;
    printf("Enter the port number of the SMTP server: ");
    scanf("%d", &port);

    // Create a socket for connecting to the SMTP server
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the address of the SMTP server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the SMTP server
    char buf[1024];
    memset(buf, 0, sizeof(buf));
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the HELO command to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "HELO %s\r\n", hostname);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    memset(buf, 0, sizeof(buf));
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the MAIL FROM command to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "MAIL FROM: <sender@example.com>\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    memset(buf, 0, sizeof(buf));
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the RCPT TO command to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "RCPT TO: <recipient@example.com>\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    memset(buf, 0, sizeof(buf));
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the DATA command to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "DATA\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    memset(buf, 0, sizeof(buf));
    if (read(sockfd, buf, sizeof(buf)) < 0) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the email message to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "Subject: Test Email\r\n\r\nThis is a test email.\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server
    memset(buf, 0, sizeof(buf));
    sprintf(buf, "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}