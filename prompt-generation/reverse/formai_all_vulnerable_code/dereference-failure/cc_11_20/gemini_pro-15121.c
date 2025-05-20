//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[MAX_LINE_LENGTH];

    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server IP address> <port number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Get server address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname() failed\n");
        exit(EXIT_FAILURE);
    }

    // Set zero to servaddr
    memset(&servaddr, 0, sizeof(servaddr));

    // Set server address
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    servaddr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "HELO localhost\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Send MAIL FROM command
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "MAIL FROM: <sender@example.com>\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Send RCPT TO command
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "RCPT TO: <recipient@example.com>\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Send DATA command
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "DATA\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Send email body
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "This is a test email.\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Send dot (.) to indicate end of email body
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, ".\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Send QUIT command
    memset(buf, 0, MAX_LINE_LENGTH);
    strcpy(buf, "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write() failed");
        exit(EXIT_FAILURE);
    }

    // Read server response
    memset(buf, 0, MAX_LINE_LENGTH);
    n = read(sockfd, buf, MAX_LINE_LENGTH);
    if (n == -1) {
        perror("read() failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", buf);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}