//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    // Receive the welcome message
    char buf[MAX_LINE];
    int n;
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the USER command
    memset(buf, 0, MAX_LINE);
    sprintf(buf, "USER %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the user response
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the PASS command
    memset(buf, 0, MAX_LINE);
    sprintf(buf, "PASS %s\r\n", argv[4]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the pass response
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the STAT command
    memset(buf, 0, MAX_LINE);
    strcpy(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the stat response
    if ((n = recv(sockfd, buf, MAX_LINE, 0)) < 0)
    {
        perror("recv");
        exit(1);
    }
    printf("%s", buf);

    // Send the LIST command
    memset(buf, 0, MAX_LINE);
    strcpy(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the list response
    while ((n = recv(sockfd, buf, MAX_LINE, 0)) > 0)
    {
        printf("%s", buf);
    }
    if (n < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the RETR command
    memset(buf, 0, MAX_LINE);
    sprintf(buf, "RETR %s\r\n", argv[5]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the retr response
    FILE *fp = fopen(argv[5], "w");
    if (fp == NULL)
    {
        perror("fopen");
        exit(1);
    }
    while ((n = recv(sockfd, buf, MAX_LINE, 0)) > 0)
    {
        fwrite(buf, n, 1, fp);
    }
    if (n < 0)
    {
        perror("recv");
        exit(1);
    }
    fclose(fp);

    // Send the QUIT command
    memset(buf, 0, MAX_LINE);
    strcpy(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);
    return 0;
}