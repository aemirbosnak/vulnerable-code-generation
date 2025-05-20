//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the sender and recipient addresses.
    char *sender = argv[1];
    char *recipient = argv[2];

    // Get the subject and body of the message.
    char *subject = argv[3];
    char *body = argv[4];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server.
    struct hostent *host = gethostbyname("smtp.example.com");
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char *helo_command = "HELO localhost\r\n";
    if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the MAIL FROM command.
    char *mail_from_command = "MAIL FROM: <%s>\r\n";
    char *mail_from_command_formatted = malloc(strlen(mail_from_command) + strlen(sender));
    sprintf(mail_from_command_formatted, mail_from_command, sender);
    if (send(sockfd, mail_from_command_formatted, strlen(mail_from_command_formatted), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the RCPT TO command.
    char *rcpt_to_command = "RCPT TO: <%s>\r\n";
    char *rcpt_to_command_formatted = malloc(strlen(rcpt_to_command) + strlen(recipient));
    sprintf(rcpt_to_command_formatted, rcpt_to_command, recipient);
    if (send(sockfd, rcpt_to_command_formatted, strlen(rcpt_to_command_formatted), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the DATA command.
    char *data_command = "DATA\r\n";
    if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the message.
    char *message = "Subject: %s\r\n\r\n%s\r\n.";
    char *message_formatted = malloc(strlen(message) + strlen(subject) + strlen(body));
    sprintf(message_formatted, message, subject, body);
    if (send(sockfd, message_formatted, strlen(message_formatted), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send the QUIT command.
    char *quit_command = "QUIT\r\n";
    if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}