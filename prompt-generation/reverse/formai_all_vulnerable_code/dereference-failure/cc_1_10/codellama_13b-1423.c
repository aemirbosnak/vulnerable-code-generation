//Code Llama-13B DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
/*
 * imap_client.c
 *
 * A simple IMAP client program written in C,
 * following the style of Ken Thompson.
 *
 * Usage: ./imap_client [IMAP server] [username] [password]
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s [IMAP server] [username] [password]\n", argv[0]);
        return 1;
    }

    const char *server = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    struct addrinfo *server_info;
    int err = getaddrinfo(server, NULL, &hints, &server_info);
    if (err != 0) {
        fprintf(stderr, "getaddrinfo() failed: %s\n", gai_strerror(err));
        return 1;
    }

    int sock = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    if (connect(sock, server_info->ai_addr, server_info->ai_addrlen) < 0) {
        perror("connect() failed");
        return 1;
    }

    freeaddrinfo(server_info);

    char buf[BUF_SIZE];
    snprintf(buf, BUF_SIZE, "* OK [CAPABILITY IMAP4rev1 STARTTLS LOGINDISABLED] IMAP4rev1 server ready.\r\n");
    send(sock, buf, strlen(buf), 0);

    snprintf(buf, BUF_SIZE, "A001 CAPABILITY\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "A002 LOGIN %s %s\r\n", username, password);
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "A003 SELECT INBOX\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "A004 FETCH 1:* FLAGS\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    snprintf(buf, BUF_SIZE, "A005 LOGOUT\r\n");
    send(sock, buf, strlen(buf), 0);

    recv(sock, buf, BUF_SIZE, 0);
    printf("%s", buf);

    close(sock);

    return 0;
}