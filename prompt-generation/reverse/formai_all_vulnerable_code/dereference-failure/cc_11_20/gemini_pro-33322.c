//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define SMTP_PORT 25
#define BUF_SIZE 4096

int main(int argc, char **argv) {
    // Check for arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <recipient> <subject> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Initialize variables
    struct sockaddr_in serv_addr;
    int sockfd, n;
    char buf[BUF_SIZE];

    // Get recipient, subject, and message
    char *recipient = argv[1];
    char *subject = argv[2];
    char *message = argv[3];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Set server address
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        perror("Error getting host by name");
        close(sockfd);
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send HELO command
    sprintf(buf, "HELO %s\r\n", "example.com");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending HELO command");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server response
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving server response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send MAIL FROM command
    sprintf(buf, "MAIL FROM: <test@example.com>\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending MAIL FROM command");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server response
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving server response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", recipient);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending RCPT TO command");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server response
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving server response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send DATA command
    sprintf(buf, "DATA\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending DATA command");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server response
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving server response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send email message
    sprintf(buf, "From: test@example.com\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.", recipient, subject, message);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending email message");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send QUIT command
    sprintf(buf, "QUIT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n < 0) {
        perror("Error sending QUIT command");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive server response
    n = recv(sockfd, buf, BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving server response");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}