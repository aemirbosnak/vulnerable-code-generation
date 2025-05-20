//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the SMTP server
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the HELO command
    char buf[1024];
    snprintf(buf, sizeof(buf), "HELO %s\r\n", host->h_name);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 5, 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the message
    if (send(sockfd, argv[3], strlen(argv[3]), 0) == -1) {
        perror("send");
        return 1;
    }

    // Send the dot to indicate the end of the message
    if (send(sockfd, ".\r\n", 3, 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}