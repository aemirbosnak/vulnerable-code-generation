//Falcon-180B DATASET v1.0 Category: Networking ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, newsockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next)
    {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1)
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

    printf("Connected to server\n");

    while (1)
    {
        char send_buf[1024];
        char recv_buf[1024];

        memset(send_buf, 0, sizeof(send_buf));
        memset(recv_buf, 0, sizeof(recv_buf));

        printf("Enter message to send: ");
        fgets(send_buf, sizeof(send_buf), stdin);

        numbytes = send(sockfd, send_buf, strlen(send_buf), 0);

        if (numbytes <= 0)
        {
            printf("Send failed\n");
            break;
        }

        numbytes = recv(sockfd, recv_buf, sizeof(recv_buf), 0);

        if (numbytes <= 0)
        {
            printf("Recv failed\n");
            break;
        }

        printf("Received message: %s\n", recv_buf);
    }

    close(sockfd);

    return 0;
}