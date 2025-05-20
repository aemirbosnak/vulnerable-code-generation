//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <to> <from> <message>\n", argv[0]);
        return 1;
    }

    char *to = argv[1];
    char *from = argv[2];
    char *message = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buf[1024];

    // Receive the welcome message
    int recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the HELO command
    snprintf(buf, sizeof(buf), "HELO localhost\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the HELO command
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", from);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the MAIL FROM command
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", to);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the RCPT TO command
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the DATA command
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the message
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return 1;
    }

    // Send the CRLF after the message
    snprintf(buf, sizeof(buf), "\r\n.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the message
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response to the QUIT command
    recv_len = recv(sockfd, buf, sizeof(buf), 0);
    if (recv_len == -1) {
        perror("recv");
        return 1;
    }
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}