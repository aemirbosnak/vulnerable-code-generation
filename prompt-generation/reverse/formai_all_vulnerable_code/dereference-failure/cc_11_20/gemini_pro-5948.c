//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <time.h>

#define SMTP_PORT 25

int main(int argc, char **argv)
{
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <server> <from> <to> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the server.
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the server's greeting.
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the HELO command.
    snprintf(buf, sizeof(buf), "HELO %s\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the MAIL FROM command.
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the RCPT TO command.
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the DATA command.
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the message.
    if (send(sockfd, argv[4], strlen(argv[4]), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the CRLF to end the message.
    snprintf(buf, sizeof(buf), "\r\n.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the QUIT command.
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}