//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define SMTP_PORT 25
#define MAXLINE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char *smtp_server = "mail.example.com";
    char *sender = "me@example.com";
    char *receiver = "you@example.com";
    char *subject = "Test email";
    char *body = "This is a test email.";

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    // Resolve the server's address
    struct hostent *h = gethostbyname(smtp_server);
    if (h == NULL) {
        perror("gethostbyname");
        return 1;
    }

    // Set up the server's address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SMTP_PORT);
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return 1;
    }

    // Read the server's greeting
    char buf[MAXLINE];
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the HELO command
    snprintf(buf, sizeof(buf), "HELO %s\r\n", smtp_server);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", sender);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", receiver);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the email body
    snprintf(buf, sizeof(buf), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return 1;
    }

    // Read the server's response
    if (read(sockfd, buf, MAXLINE) < 0) {
        perror("read");
        return 1;
    }

    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}