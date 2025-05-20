//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[1024];

    if (argc != 3)
    {
        printf("Usage: %s <server IP address> <username>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        return 1;
    }

    // Receive the welcome message
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the USER command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the PASS command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the STAT command
    snprintf(buf, sizeof(buf), "STAT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the STAT command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the LIST command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the RETR command
    snprintf(buf, sizeof(buf), "RETR 1\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the RETR command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the DELE command
    snprintf(buf, sizeof(buf), "DELE 1\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the DELE command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("write");
        return 1;
    }

    // Receive the response to the QUIT command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0)
    {
        perror("read");
        return 1;
    }
    printf("%s", buf);

    close(sockfd);

    return 0;
}