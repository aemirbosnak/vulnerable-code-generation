//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#define PORT_SCAN_MAX 10000

void scan_ports(int target_port)
{
    int sockfd;
    struct sockaddr_in sock_addr;
    char buf[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(target_port));

    if (sockfd < 0)
    {
        perror("Error creating socket");
        return;
    }

    sock_addr.sin_port = target_port;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
    {
        perror("Error connecting to socket");
        close(sockfd);
        return;
    }

    printf("Port %d is open\n", target_port);

    close(sockfd);
}

int main()
{
    int target_port;
    char target_ip[256];

    printf("Enter target IP: ");
    scanf("%s", target_ip);

    printf("Enter target port: ");
    scanf("%d", &target_port);

    scan_ports(target_port);

    return 0;
}