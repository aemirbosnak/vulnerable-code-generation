//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: Claude Shannon
// SMTP Client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define MAX_SMTP_COMMAND_LEN 256

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buf[MAX_SMTP_COMMAND_LEN];
    char recv_buf[MAX_LINE_LEN];
    char *host, *port;
    int n, len;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    port = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s on port %s\n", host, port);

    while (1) {
        fgets(send_buf, MAX_SMTP_COMMAND_LEN, stdin);
        if (feof(stdin)) {
            break;
        }
        send(sockfd, send_buf, strlen(send_buf), 0);

        n = recv(sockfd, recv_buf, MAX_LINE_LEN, 0);
        if (n < 0) {
            perror("recv");
            break;
        }
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    close(sockfd);

    return 0;
}