//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 4096

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd, n;
    char buf[BUFSIZE];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Error converting host address: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    printf("Connected to mail server at %s:%s\n", argv[1], argv[2]);

    while (1) {
        printf("My dear Watson, enter your command (or quit to leave): ");
        fgets(buf, BUFSIZE, stdin);
        if (strcmp(buf, "quit\n") == 0) {
            break;
        }

        n = strlen(buf);
        if (buf[n - 1] == '\n') {
            buf[n - 1] = '\0';
        }

        if (send(sockfd, buf, n, 0) < 0) {
            fprintf(stderr, "Error sending command: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        n = recv(sockfd, buf, BUFSIZE, 0);
        if (n < 0) {
            fprintf(stderr, "Error receiving response: %s\n", strerror(errno));
            return EXIT_FAILURE;
        }

        buf[n] = '\0';
        printf("The server says: %s\n", buf);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}