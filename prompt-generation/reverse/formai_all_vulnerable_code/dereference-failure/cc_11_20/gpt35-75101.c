//FormAI DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    int sockfd, status;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC; // use IPv4 or IPv6, whichever
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo(argv[1], NULL, &hints, &res)) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 2;
    }

    printf("Port scanner for host %s\n", argv[1]);
    printf("=========================================\n\n");

    for (struct addrinfo *p = res; p != NULL; p = p->ai_next)
    {
        void *addr;
        char *ipver;

        if (p->ai_family == AF_INET)  
        {
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";

        }
        else
        {
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        if (inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr) == NULL)
        {
            perror("inet_ntop error");
            return 3;
        }

        printf("Scanning ports for %s: %s\n", ipver, ipstr);
        printf("-----------------------------------------\n\n");

        for (int port = 1; port <= 65535; port++) 
        {
            sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
            if (sockfd == -1)
            {
                perror("socket error");
                continue;
            }

            struct sockaddr_storage addr;
            socklen_t addrlen = sizeof addr;
            memset(&addr, 0, addrlen);
            addr.ss_family = p->ai_family;

            if (p->ai_family == AF_INET)
            {
                struct sockaddr_in *ipv4 = (struct sockaddr_in *)&addr;
                ipv4->sin_addr = ((struct sockaddr_in *)p->ai_addr)->sin_addr;
                ipv4->sin_port = htons(port);
            }
            else
            {
                struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)&addr;
                ipv6->sin6_addr = ((struct sockaddr_in6 *)p->ai_addr)->sin6_addr;
                ipv6->sin6_port = htons(port);
            }

            int sockopt = 1;
            if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(int)) == -1)
            {
                perror("setsockopt error");
                close(sockfd);
                continue;
            }

            if (connect(sockfd, (struct sockaddr *)&addr, addrlen) == -1)
            {
                close(sockfd);
                continue;
            }

            printf("Port %d is open\n", port);

            close(sockfd);
        }

        printf("\n");
    }

    freeaddrinfo(res);

    return 0;
}