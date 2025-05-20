//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define POP3_PORT 110
#define MAX_MSG_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n, i, max, recv_size;
    char buf[MAX_MSG_SIZE];
    char *msg_end;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if (argc != 3) {
        printf("Usage: %s <server> <user>\n", argv[0]);
        exit(1);
    }

    if ((server = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        exit(2);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(3);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(4);
    }

    printf("Connected to %s\n", inet_ntoa(server_addr.sin_addr));

    n = write(sockfd, "USER ", 5);
    n = write(sockfd, argv[2], strlen(argv[2]));
    n = write(sockfd, "\r\n", 2);

    n = read(sockfd, buf, MAX_MSG_SIZE);
    if (n < 0) {
        perror("read");
        exit(5);
    }
    printf("Server response: %s\n", buf);

    n = write(sockfd, "PASS ", 5);
    n = write(sockfd, argv[2], strlen(argv[2]));
    n = write(sockfd, "\r\n", 2);

    n = read(sockfd, buf, MAX_MSG_SIZE);
    if (n < 0) {
        perror("read");
        exit(6);
    }
    printf("Server response: %s\n", buf);

    n = write(sockfd, "LIST\r\n", 6);

    n = read(sockfd, buf, MAX_MSG_SIZE);
    if (n < 0) {
        perror("read");
        exit(7);
    }
    printf("Server response: %s\n", buf);

    msg_end = strstr(buf, "\r\n.\r\n");
    if (msg_end != NULL) {
        max = msg_end - buf;
    } else {
        max = strlen(buf);
    }
    for (i = 0; i < max; i++) {
        if (buf[i] == ' ') {
            buf[i] = '\0';
        }
    }

    n = write(sockfd, "RETR ", 5);
    n = write(sockfd, buf, strlen(buf));
    n = write(sockfd, "\r\n", 2);

    n = read(sockfd, buf, MAX_MSG_SIZE);
    if (n < 0) {
        perror("read");
        exit(8);
    }
    printf("Server response: %s\n", buf);

    n = write(sockfd, "QUIT\r\n", 6);

    n = read(sockfd, buf, MAX_MSG_SIZE);
    if (n < 0) {
        perror("read");
        exit(9);
    }
    printf("Server response: %s\n", buf);

    close(sockfd);

    return 0;
}