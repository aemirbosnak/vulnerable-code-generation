//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <server> <port> <sender> <recipient>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return 1;
    }

    // Send the HELO command
    char buf[1024];
    snprintf(buf, sizeof(buf), "HELO %s\r\n", argv[0]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", argv[4]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the message body
    snprintf(buf, sizeof(buf), "Subject: %s\r\n\r\n", argv[5]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    snprintf(buf, sizeof(buf), "%s\r\n", argv[6]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Send the dot to indicate the end of the message
    snprintf(buf, sizeof(buf), ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Read the response
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}