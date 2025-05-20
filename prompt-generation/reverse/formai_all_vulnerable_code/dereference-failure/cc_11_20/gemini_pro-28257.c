//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAXLINE 1024

// Function to send an email
int send_email(char *server, char *port, char *sender, char *recipient, char *subject, char *body) {
    int sockfd, n;
    struct addrinfo hints, *res;
    char buf[MAXLINE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Get the server's address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(server, port, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        return -1;
    }

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", server);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    n = recv(sockfd, buf, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return -1;
    }

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", sender);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    n = recv(sockfd, buf, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return -1;
    }

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", recipient);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    n = recv(sockfd, buf, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return -1;
    }

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    n = recv(sockfd, buf, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(buf, "354", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return -1;
    }

    // Send the email body
    sprintf(buf, "From: %s\r\n", sender);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    sprintf(buf, "To: %s\r\n", recipient);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    sprintf(buf, "Subject: %s\r\n", subject);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    sprintf(buf, "\r\n%s\r\n", body);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Send the dot to indicate the end of the email body
    sprintf(buf, ".\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Receive the server's response
    n = recv(sockfd, buf, MAXLINE, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }

    // Check the server's response
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return -1;
    }

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 7) {
        fprintf(stderr, "Usage: %s server port sender recipient subject body\n", argv[0]);
        return -1;
    }

    // Get the email server, port, sender, recipient, subject, and body from the command line arguments
    char *server = argv[1];
    char *port = argv[2];
    char *sender = argv[3];
    char *recipient = argv[4];
    char *subject = argv[5];
    char *body = argv[6];

    // Send the email
    if (send_email(server, port, sender, recipient, subject, body) != 0) {
        fprintf(stderr, "Error sending email\n");
        return -1;
    }

    return 0;
}