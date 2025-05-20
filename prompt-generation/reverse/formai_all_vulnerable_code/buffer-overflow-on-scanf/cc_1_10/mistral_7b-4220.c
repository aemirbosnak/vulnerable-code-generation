//MISTRAL-7B DATASET v1.0 Category: Email Client ; Style: synchronous
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 25
#define MAX_LINE 256
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    char buffer[BUFFER_SIZE];
    char *helo = "HELO localhost\r\n";
    char *mail_from = "MAIL FROM:<sender@example.com>\r\n";
    char *rcpt_to = "RCPT TO:<recipient@example.com>\r\n";
    char *data = "DATA\r\n";
    char *subject = "Subject: Test Email\r\n";
    char *message = "Content-Type: text/plain\r\n\r\nTest Email Message.\r\n.";

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket: ");

    portno = 0;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serveraddr.sin_addr) <= 0) {
        die("inet_pton: ");
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        die("connect: ");
    }

    write(sockfd, helo, strlen(helo));
    if (read(sockfd, buffer, MAX_LINE) < 0) die("read: ");

    write(sockfd, mail_from, strlen(mail_from));
    if (read(sockfd, buffer, MAX_LINE) < 0) die("read: ");

    printf("Please enter recipient's email address: ");
    scanf("%s", buffer);
    strcat(rcpt_to, buffer);

    write(sockfd, rcpt_to, strlen(rcpt_to));
    if (read(sockfd, buffer, MAX_LINE) < 0) die("read: ");

    write(sockfd, data, strlen(data));
    if (read(sockfd, buffer, MAX_LINE) < 0) die("read: ");

    printf("Please enter email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strlen(subject) - 1] = '\0';

    printf("Please enter email message: ");
    fgets(message, sizeof(message), stdin);
    message[strlen(message) - 1] = '\0';
    strcat(message, "\r\n.");

    write(sockfd, subject, strlen(subject));
    write(sockfd, message, strlen(message));

    if (read(sockfd, buffer, MAX_LINE) < 0) die("read: ");

    close(sockfd);
    return 0;
}