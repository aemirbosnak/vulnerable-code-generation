//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUF_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[MAX_BUF_LEN];
    memset(buf, 0, sizeof(buf));

    ssize_t nbytes;
    nbytes = recv(sockfd, buf, MAX_BUF_LEN - 1, 0);
    if (nbytes == -1) {
        perror("recv");
        exit(1);
    }

    buf[nbytes] = '\0';
    printf("Server: %s", buf);

    while (1) {
        memset(buf, 0, sizeof(buf));
        printf("Command: ");
        fflush(stdout);
        nbytes = read(STDIN_FILENO, buf, MAX_BUF_LEN - 1);
        if (nbytes == 0) {
            break;
        } else if (nbytes == -1) {
            perror("read");
            exit(1);
        }

        buf[nbytes] = '\0';
        if (strcmp(buf, "exit") == 0) {
            break;
        }

        nbytes = send(sockfd, buf, strlen(buf), 0);
        if (nbytes == -1) {
            perror("send");
            exit(1);
        }

        memset(buf, 0, sizeof(buf));
        nbytes = recv(sockfd, buf, MAX_BUF_LEN - 1, 0);
        if (nbytes == -1) {
            perror("recv");
            exit(1);
        }

        buf[nbytes] = '\0';
        printf("Server: %s", buf);
    }

    close(sockfd);
    return 0;
}