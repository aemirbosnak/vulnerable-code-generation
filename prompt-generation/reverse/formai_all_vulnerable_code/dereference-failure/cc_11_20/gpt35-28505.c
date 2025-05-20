//FormAI DATASET v1.0 Category: Email Client ; Style: synchronous
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 4096
#define SERVER_PORT 25

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <recipient email address>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    char *recipient = argv[2];

    /* create the TCP socket */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    /* get the server host information */
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Unknown host %s\n", hostname);
        exit(1);
    }

    /* construct the server address structure */
    struct sockaddr_in serveraddr;
    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy(server->h_addr, &serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(SERVER_PORT);

    /* connect to server */
    if (connect(sockfd, (struct sockaddr*)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buf[MAX_LINE];

    /* read the greeting from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send HELO command */
    snprintf(buf, MAX_LINE, "HELO %s\r\n", hostname);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send MAIL FROM command */
    snprintf(buf, MAX_LINE, "MAIL FROM:<%s>\r\n", recipient);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send RCPT TO command */
    snprintf(buf, MAX_LINE, "RCPT TO:<%s>\r\n", recipient);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send DATA command */
    snprintf(buf, MAX_LINE, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send email message */
    printf("Enter message, end with <CTRL-D>:\n");

    int n;
    while ((n = read(STDIN_FILENO, buf, MAX_LINE)) > 0) {
        if (send(sockfd, buf, n, 0) < 0) {
            perror("send");
            exit(1);
        }
    }

    /* send end-of-message command */
    snprintf(buf, MAX_LINE, "\r\n.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* send QUIT command */
    snprintf(buf, MAX_LINE, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    /* read the response from the server */
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s", buf);

    /* close the socket */
    close(sockfd);

    return 0;
}