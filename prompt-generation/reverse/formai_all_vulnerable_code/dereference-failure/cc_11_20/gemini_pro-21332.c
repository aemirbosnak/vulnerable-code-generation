//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define MAX_LINE 512

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <recipient> <subject> <message>\n", argv[0]);
        exit(1);
    }

    char *recipient = argv[1];
    char *subject = argv[2];
    char *message = argv[3];

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char *helo_command = "HELO localhost\r\n";
    if (send(sockfd, helo_command, strlen(helo_command), 0) < 0) {
        perror("send");
        exit(1);
    }

    char buffer[MAX_LINE];
    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    char *mail_from_command = "MAIL FROM: <sender@localhost>\r\n";
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    char *rcpt_to_command = "RCPT TO: <%s>\r\n", formatted_rcpt_to_command[MAX_LINE];
    sprintf(formatted_rcpt_to_command, rcpt_to_command, recipient);
    if (send(sockfd, formatted_rcpt_to_command, strlen(formatted_rcpt_to_command), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    char *data_command = "DATA\r\n";
    if (send(sockfd, data_command, strlen(data_command), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    char *email_body = "Subject: %s\r\n\r\n%s\r\n.\r\n", formatted_email_body[MAX_LINE];
    sprintf(formatted_email_body, email_body, subject, message);
    if (send(sockfd, formatted_email_body, strlen(formatted_email_body), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    char *quit_command = "QUIT\r\n";
    if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
        perror("send");
        exit(1);
    }

    if (recv(sockfd, buffer, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    close(sockfd);

    return 0;
}