//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <server> <username> <password>\n", argv[0]);
        return 1;
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        fprintf(stderr, "%s: unknown host\n", server);
        return 1;
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(993),
        .sin_addr = *((struct in_addr *)he->h_addr)
    };

    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[BUF_SIZE];
    ssize_t n = recv(server_fd, buf, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "a001 LOGIN %s %s\r\n", username, password);
    if (send(server_fd, buf, strlen(buf), MSG_NOSIGNAL) < 0) {
        perror("send");
        return 1;
    }

    n = recv(server_fd, buf, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "a002 SELECT INBOX\r\n");
    if (send(server_fd, buf, strlen(buf), MSG_NOSIGNAL) < 0) {
        perror("send");
        return 1;
    }

    n = recv(server_fd, buf, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "a003 FETCH 1:* (FLAGS BODY[HEADER.FIELDS (SUBJECT FROM DATE)])\r\n");
    if (send(server_fd, buf, strlen(buf), MSG_NOSIGNAL) < 0) {
        perror("send");
        return 1;
    }

    n = recv(server_fd, buf, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "a004 LOGOUT\r\n");
    if (send(server_fd, buf, strlen(buf), MSG_NOSIGNAL) < 0) {
        perror("send");
        return 1;
    }

    n = recv(server_fd, buf, BUF_SIZE - 1, 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }
    buf[n] = '\0';
    printf("%s", buf);

    close(server_fd);

    return 0;
}