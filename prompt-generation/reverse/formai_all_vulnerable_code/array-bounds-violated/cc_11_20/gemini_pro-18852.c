//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define IMAP_PORT 143

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in servaddr;
    char *hostname, *username, *password;
    char buf[1024];
    int n;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname username password\n", argv[0]);
        return -1;
    }

    hostname = argv[1];
    username = argv[2];
    password = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(IMAP_PORT);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) != 1) {
        perror("inet_pton");
        return -1;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return -1;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, sizeof(buf) - 1, "LOGIN %s %s\r\n", username, password);
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n == -1) {
        perror("recv");
        return -1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, sizeof(buf) - 1, "LIST \"\"\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    while ((n = recv(sockfd, buf, sizeof(buf) - 1, 0)) > 0) {
        buf[n] = '\0';
        printf("%s", buf);
    }

    if (n == -1) {
        perror("recv");
        return -1;
    }

    snprintf(buf, sizeof(buf) - 1, "LOGOUT\r\n");
    n = send(sockfd, buf, strlen(buf), 0);
    if (n == -1) {
        perror("send");
        return -1;
    }

    close(sockfd);

    return 0;
}