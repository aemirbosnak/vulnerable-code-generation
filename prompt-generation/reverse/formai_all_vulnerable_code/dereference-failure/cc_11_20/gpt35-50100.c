//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 25
#define MAXLEN      1024

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 2) {
        printf("Usage: %s <smtp server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error getting host");
        exit(EXIT_FAILURE);
    }

    // Set socket parameters and connect to server
    struct sockaddr_in serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(SERVER_PORT);
    memcpy(&serveraddr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Read server response
    char buf[MAXLEN];
    int nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send HELO command
    char helo[MAXLEN];
    snprintf(helo, MAXLEN, "HELO %s\r\n", argv[1]);
    if (send(sockfd, helo, strlen(helo), 0) == -1) {
        perror("Error sending HELO command");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send MAIL FROM command
    char mailfrom[MAXLEN];
    printf("Sender email address: ");
    fgets(mailfrom, MAXLEN, stdin);
    int len = strlen(mailfrom);
    mailfrom[len-1] = '\0';  // remove newline character
    snprintf(buf, MAXLEN, "MAIL FROM: <%s>\r\n", mailfrom);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending MAIL FROM command");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send RCPT TO command
    char rcptto[MAXLEN];
    printf("Recipient email address: ");
    fgets(rcptto, MAXLEN, stdin);
    len = strlen(rcptto);
    rcptto[len-1] = '\0';  // remove newline character
    snprintf(buf, MAXLEN, "RCPT TO: <%s>\r\n", rcptto);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending RCPT TO command");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) == -1) {
        perror("Error sending DATA command");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send email body
    printf("Subject: ");
    char subject[MAXLEN];
    fgets(subject, MAXLEN, stdin);
    printf("Message: ");
    char message[MAXLEN];
    fgets(message, MAXLEN, stdin);
    snprintf(buf, MAXLEN, "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", mailfrom, rcptto, subject, message);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("Error sending email body");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Send QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }

    // Read server response
    nread = read(sockfd, buf, MAXLEN);
    if (nread == -1) {
        perror("Error reading from socket");
        exit(EXIT_FAILURE);
    }
    buf[nread] = '\0';
    printf("%s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}