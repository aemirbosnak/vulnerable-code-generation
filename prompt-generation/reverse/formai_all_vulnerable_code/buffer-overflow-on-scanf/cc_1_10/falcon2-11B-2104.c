//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    char buf[256];

    /* Create socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    /* Internet domain, IPv4 address, HTTP port */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Enter URL: ");
    scanf("%s", buf);

    /* Send GET request */
    n = write(sockfd, buf, strlen(buf));
    if (n < 0)
    {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    /* Receive server response */
    n = read(sockfd, buf, 256);
    if (n < 0)
    {
        perror("ERROR reading from socket");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    close(sockfd);
    return 0;
}