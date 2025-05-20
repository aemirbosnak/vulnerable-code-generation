//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the sender and recipient addresses
    char *sender = argv[1];
    char *recipient = argv[2];

    // Get the message body
    char *message = argv[3];

    // Create a socket for the SMTP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: could not resolve hostname\n");
        return EXIT_FAILURE;
    }
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the SMTP server
    char buffer[1024];
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received welcome message: %s\n", buffer);

    // Send the HELO command to the SMTP server
    sprintf(buffer, "HELO localhost\r\n");
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received HELO response: %s\n", buffer);

    // Send the MAIL FROM command to the SMTP server
    sprintf(buffer, "MAIL FROM: <%s>\r\n", sender);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received MAIL FROM response: %s\n", buffer);

    // Send the RCPT TO command to the SMTP server
    sprintf(buffer, "RCPT TO: <%s>\r\n", recipient);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received RCPT TO response: %s\n", buffer);

    // Send the DATA command to the SMTP server
    sprintf(buffer, "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received DATA response: %s\n", buffer);

    // Send the message body to the SMTP server
    sprintf(buffer, "%s\r\n.\r\n", message);
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received DATA response: %s\n", buffer);

    // Send the QUIT command to the SMTP server
    sprintf(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server
    if (read(sockfd, buffer, sizeof(buffer)) == -1) {
        perror("read");
        return EXIT_FAILURE;
    }
    printf("Received QUIT response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}