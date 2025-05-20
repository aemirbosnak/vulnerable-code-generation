//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 25

int main() {
    // Get the hostname and port of the SMTP server
    char hostname[1024];
    int port = SMTP_PORT;
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);
    printf("Enter the port of the SMTP server (default: %d): ", SMTP_PORT);
    scanf("%d", &port);

    // Create a socket for connecting to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve the hostname to an IP address
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set up the socket address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    char buffer[1024];
    sprintf(buffer, "HELO localhost\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <user@example.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <user@example.com>\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    sprintf(buffer, "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the email message
    sprintf(buffer, "Subject: Test email\r\n\r\nThis is a test email.\r\n.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    sprintf(buffer, "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}