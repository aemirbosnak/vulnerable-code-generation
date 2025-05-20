//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFSIZE 1024
#define POP3_PORT "110"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname user\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(argv[1], POP3_PORT, &hints, &servinfo) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", strerror(errno));
        exit(1);
    }

    char user_cmd[BUFSIZE], pass_cmd[BUFSIZE], list_cmd[BUFSIZE];
    snprintf(user_cmd, BUFSIZE, "USER %s\r\n", argv[2]);
    snprintf(pass_cmd, BUFSIZE, "PASS %s\r\n", getpass("Password: "));
    snprintf(list_cmd, BUFSIZE, "LIST\r\n");

    for (p = servinfo; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            continue;
        }
        break;
    }
    freeaddrinfo(servinfo);
    if (p == NULL) {
        fprintf(stderr, "Unable to connect to %s:%s\n", argv[1], POP3_PORT);
        exit(1);
    }

    char buf[BUFSIZE];
    int bytes_recv = recv(sockfd, buf, BUFSIZE - 1, 0);
    buf[bytes_recv] = '\0';
    printf("%s", buf);

    int send_result = send(sockfd, user_cmd, strlen(user_cmd), 0);
    if (send_result == -1) {
        fprintf(stderr, "Error sending command: %s\n", strerror(errno));
        close(sockfd);
        exit(1);
    }

    bytes_recv = recv(sockfd, buf, BUFSIZE - 1, 0);
    buf[bytes_recv] = '\0';
    printf("%s", buf);

    send_result = send(sockfd, pass_cmd, strlen(pass_cmd), 0);
    if (send_result == -1) {
        fprintf(stderr, "Error sending command: %s\n", strerror(errno));
        close(sockfd);
        exit(1);
    }

    bytes_recv = recv(sockfd, buf, BUFSIZE - 1, 0);
    buf[bytes_recv] = '\0';
    printf("%s", buf);

    send_result = send(sockfd, list_cmd, strlen(list_cmd), 0);
    if (send_result == -1) {
        fprintf(stderr, "Error sending command: %s\n", strerror(errno));
        close(sockfd);
        exit(1);
    }

    bytes_recv = recv(sockfd, buf, BUFSIZE - 1, 0);
    buf[bytes_recv] = '\0';
    printf("%s", buf);

    close(sockfd);
    return 0;
}