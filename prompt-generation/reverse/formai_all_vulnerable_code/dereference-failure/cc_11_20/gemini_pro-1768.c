//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
/*
 * SMTP Client Example
 *
 * This program demonstrates how to use the SMTP protocol to send an email message.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    // Check if the user provided enough arguments.
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_address> <to_address> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the SMTP server address.
    struct hostent *smtp_server = gethostbyname(argv[1]);
    if (smtp_server == NULL) {
        fprintf(stderr, "Error: could not resolve SMTP server address.\n");
        return EXIT_FAILURE;
    }

    // Create a socket for communicating with the SMTP server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket.\n");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in smtp_addr;
    memset(&smtp_addr, 0, sizeof(smtp_addr));
    smtp_addr.sin_family = AF_INET;
    smtp_addr.sin_port = htons(SMTP_PORT);
    smtp_addr.sin_addr = *(struct in_addr *)smtp_server->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&smtp_addr, sizeof(smtp_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the greeting from the SMTP server.
    char greeting[512];
    if (recv(sockfd, greeting, sizeof(greeting), 0) < 0) {
        fprintf(stderr, "Error: could not receive greeting from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server.
    char helo[] = "HELO example.com\r\n";
    if (send(sockfd, helo, strlen(helo), 0) < 0) {
        fprintf(stderr, "Error: could not send HELO command to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    char response[512];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server.
    char mail_from[512];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM: %s\r\n", argv[2]);
    if (send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        fprintf(stderr, "Error: could not send MAIL FROM command to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server.
    char rcpt_to[512];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: %s\r\n", argv[3]);
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        fprintf(stderr, "Error: could not send RCPT TO command to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server.
    char data[] = "DATA\r\n";
    if (send(sockfd, data, strlen(data), 0) < 0) {
        fprintf(stderr, "Error: could not send DATA command to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the message to the SMTP server.
    if (send(sockfd, argv[4], strlen(argv[4]), 0) < 0) {
        fprintf(stderr, "Error: could not send message to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the end of message dot to the SMTP server.
    char dot[] = ".\r\n";
    if (send(sockfd, dot, strlen(dot), 0) < 0) {
        fprintf(stderr, "Error: could not send end of message dot to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server.
    char quit[] = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) < 0) {
        fprintf(stderr, "Error: could not send QUIT command to SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Read the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        fprintf(stderr, "Error: could not receive response from SMTP server.\n");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}