//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
    int sockfd, n;
    char recv_buf[1024];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <host> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    bzero(recv_buf, 1024);
    n = read(sockfd, recv_buf, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", recv_buf);

    bzero(recv_buf, 1024);
    sprintf(recv_buf, "USER %s\r\n", argv[2]);
    n = write(sockfd, recv_buf, strlen(recv_buf));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    bzero(recv_buf, 1024);
    n = read(sockfd, recv_buf, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", recv_buf);

    bzero(recv_buf, 1024);
    sprintf(recv_buf, "PASS %s\r\n", argv[3]);
    n = write(sockfd, recv_buf, strlen(recv_buf));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    bzero(recv_buf, 1024);
    n = read(sockfd, recv_buf, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", recv_buf);

    bzero(recv_buf, 1024);
    sprintf(recv_buf, "LIST\r\n");
    n = write(sockfd, recv_buf, strlen(recv_buf));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    bzero(recv_buf, 1024);
    n = read(sockfd, recv_buf, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", recv_buf);

    bzero(recv_buf, 1024);
    sprintf(recv_buf, ".\r\n");
    n = write(sockfd, recv_buf, strlen(recv_buf));
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    bzero(recv_buf, 1024);
    n = read(sockfd, recv_buf, 1023);
    if (n < 0)
    {
        fprintf(stderr, "ERROR: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }
    printf("%s", recv_buf);

    close(sockfd);

    return EXIT_SUCCESS;
}