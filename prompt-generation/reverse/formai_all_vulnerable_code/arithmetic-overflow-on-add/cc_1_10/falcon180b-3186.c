//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100
#define PORT 7
#define SA struct sockaddr

int main()
{
    int sock, len, i, n, fd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAX];
    fd_set readfds;

    sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock < 0)
    {
        perror("socket error");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sock, (SA *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind error");
        exit(1);
    }

    FD_ZERO(&readfds);

    FD_SET(sock, &readfds);

    select(sock + 1, &readfds, NULL, NULL, NULL);

    while (1)
    {
        FD_ZERO(&readfds);

        FD_SET(sock, &readfds);

        select(sock + 1, &readfds, NULL, NULL, NULL);

        for (i = 0; i < FD_SETSIZE; i++)
        {
            if (FD_ISSET(i, &readfds))
            {
                if (i == sock)
                {
                    len = sizeof(cliaddr);
                    n = recvfrom(sock, buffer, MAX, 0, (SA *)&cliaddr, &len);

                    if (n <= 0)
                    {
                        perror("recvfrom error");
                        exit(1);
                    }

                    printf("Message received from %s:%d\n", inet_ntoa(cliaddr.sin_addr), ntohs(cliaddr.sin_port));

                    sendto(sock, buffer, n, 0, (SA *)&cliaddr, len);
                }
            }
        }
    }

    close(sock);

    return 0;
}