//Code Llama-13B DATASET v1.0 Category: Email Client ; Style: complex
// email_client.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <address>\n", argv[0]);
        exit(1);
    }

    struct addrinfo hints;
    struct addrinfo *server_info, *p;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int rc = getaddrinfo(argv[1], PORT, &hints, &server_info);
    if (rc != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rc));
        exit(1);
    }

    int sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    char buf[BUFSIZE];
    int n;

    while (1) {
        printf("Enter message: ");
        fgets(buf, BUFSIZE, stdin);
        n = strlen(buf);

        if (n > 1 && buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
            n--;
        }

        if (n == 0) {
            break;
        }

        send(sockfd, buf, n, 0);
    }

    close(sockfd);

    return 0;
}