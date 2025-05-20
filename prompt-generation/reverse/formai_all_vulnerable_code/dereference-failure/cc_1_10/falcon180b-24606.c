//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main()
{
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[NI_MAXSERV];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "daytime", &hints, &servinfo))!= 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next)
    {
        if (p->ai_family!= AF_INET)
        {
            continue;
        }

        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1)
        {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1)
        {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL)
    {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    inet_ntop(AF_INET, &((struct sockaddr_in *)p->ai_addr)->sin_addr, s, sizeof s);
    printf("connected to %s\n", s);

    char buffer[1024];
    while (fgets(buffer, sizeof buffer, stdin)!= NULL)
    {
        send(sockfd, buffer, strlen(buffer), 0);
    }

    close(sockfd);

    return 0;
}