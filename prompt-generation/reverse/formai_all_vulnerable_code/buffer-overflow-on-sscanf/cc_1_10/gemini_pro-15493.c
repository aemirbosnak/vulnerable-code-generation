//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_PORTS 1024

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    if (start_port < 0 || start_port > 65535 || end_port < 0 || end_port > 65535 || start_port > end_port)
    {
        printf("Invalid port range\n");
        return 1;
    }

    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons((unsigned short)start_port);
    addr.sin_addr.s_addr = inet_addr(ip_address);

    int i;
    for (i = start_port; i <= end_port; i++)
    {
        addr.sin_port = htons((unsigned short)i);
        int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
        if (ret == 0)
        {
            printf("Port %d is open\n", i);
        }
        else
        {
            printf("Port %d is closed\n", i);
        }
    }

    close(sockfd);
    return 0;
}