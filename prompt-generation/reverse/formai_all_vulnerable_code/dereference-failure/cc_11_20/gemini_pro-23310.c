//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    fprintf(stderr, "%s\n", "Connected to POP3 server.");

    char buf[1024];
    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        fprintf(stderr, "%s\n", buf);
        if (strncmp(buf, "+OK", 3) == 0) {
            break;
        }
    }

    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    char user[1024];
    printf("Enter your username: ");
    scanf("%s", user);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "USER %s\r\n", user);

    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        fprintf(stderr, "%s\n", buf);
        if (strncmp(buf, "+OK", 3) == 0) {
            break;
        }
    }

    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    char pass[1024];
    printf("Enter your password: ");
    scanf("%s", pass);

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "PASS %s\r\n", pass);

    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        fprintf(stderr, "%s\n", buf);
        if (strncmp(buf, "+OK", 3) == 0) {
            break;
        }
    }

    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    memset(buf, 0, sizeof(buf));
    sprintf(buf, "LIST\r\n");

    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        return EXIT_FAILURE;
    }

    while ((n = read(sockfd, buf, sizeof(buf))) > 0) {
        fprintf(stderr, "%s\n", buf);
        if (strncmp(buf, ".", 1) == 0) {
            break;
        }
    }

    if (n < 0) {
        perror("read");
        return EXIT_FAILURE;
    }

    close(sockfd);

    return EXIT_SUCCESS;
}