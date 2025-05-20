//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100
#define PORT 7
#define SA struct sockaddr

void die(const char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serv_addr;
    int opt = TRUE;
    int addrlen = sizeof(serv_addr);
    char buffer[MAX];
    int numbytes;
    fd_set readfds;
    struct timeval timeout;

    if (argc!= 4)
    {
        printf("Usage:./ping <ip address> <number of packets> <packet size>\n");
        return FALSE;
    }

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0)
    {
        printf("Invalid address/ Address not supported\n");
        return FALSE;
    }

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock == -1)
        die("socket failed");

    if (setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt)))
    {
        die("setsockopt");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    while (TRUE)
    {
        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);

        timeout.tv_sec = 5;
        timeout.tv_usec = 0;

        if (select(sock + 1, &readfds, NULL, NULL, &timeout) == -1)
            die("select");

        if (FD_ISSET(sock, &readfds))
        {
            numbytes = recvfrom(sock, buffer, MAX, 0, NULL, NULL);

            if (numbytes <= 0)
            {
                printf("No response from %s\n", inet_ntoa(serv_addr.sin_addr));
                break;
            }

            printf("Received a packet of size %d from %s\n", numbytes, inet_ntoa(serv_addr.sin_addr));
        }

        if (numbytes > 0)
        {
            sendto(sock, argv[3], numbytes, 0, (SA *)&serv_addr, addrlen);
        }
    }

    return TRUE;
}