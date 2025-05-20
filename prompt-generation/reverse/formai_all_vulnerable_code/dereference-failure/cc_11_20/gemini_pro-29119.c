//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <smtp_server_address> <from_address> <to_address> <message_body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the SMTP server address, port, and message body from the command line arguments.
    char *smtp_server_address = argv[1];
    int smtp_port = SMTP_PORT;
    char *from_address = argv[2];
    char *to_address = argv[3];
    char *message_body = argv[4];

    // Create a socket for communicating with the SMTP server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(smtp_port);
    if (inet_pton(AF_INET, smtp_server_address, &server_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server.
    char helo_command[256];
    snprintf(helo_command, sizeof(helo_command), "HELO %s\r\n", "myhostname");
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    char response[256];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server.
    char mail_from_command[256];
    snprintf(mail_from_command, sizeof(mail_from_command), "MAIL FROM: <%s>\r\n", from_address);
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server.
    char rcpt_to_command[256];
    snprintf(rcpt_to_command, sizeof(rcpt_to_command), "RCPT TO: <%s>\r\n", to_address);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server.
    char data_command[256];
    strcpy(data_command, "DATA\r\n");
    if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the message body to the SMTP server.
    if (send(sockfd, message_body, strlen(message_body), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the dot command to the SMTP server to indicate the end of the message.
    char dot_command[256];
    strcpy(dot_command, ".\r\n");
    if (send(sockfd, dot_command, strlen(dot_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server.
    char quit_command[256];
    strcpy(quit_command, "QUIT\r\n");
    if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}