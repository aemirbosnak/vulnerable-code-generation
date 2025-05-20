//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *recipient = argv[2];
    char *message = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_aton(hostname, &server_addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Failed to connect to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[1024];

    // Read the greeting message from the server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read greeting message: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the HELO command
    snprintf(buf, sizeof(buf), "HELO localhost\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send HELO command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the server's response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read server's response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <me@localhost>\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send MAIL FROM command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the server's response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read server's response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", recipient);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send RCPT TO command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the server's response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read server's response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send DATA command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the server's response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read server's response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the message
    snprintf(buf, sizeof(buf), "%s\r\n", message);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send message: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the dot to indicate the end of the message
    snprintf(buf, sizeof(buf), ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send dot: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Read the server's response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        fprintf(stderr, "Failed to read server's response: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        fprintf(stderr, "Failed to send QUIT command: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}