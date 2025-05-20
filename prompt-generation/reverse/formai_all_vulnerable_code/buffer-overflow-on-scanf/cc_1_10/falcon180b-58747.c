//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_port(int sockfd, int port);

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    int opt = 1;
    int port = 0;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(0);

    if (bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error binding socket\n");
        exit(1);
    }

    printf("Enter the target IP address: ");
    scanf("%s", server_addr.sin_addr.s_addr);

    printf("Enter the starting port: ");
    scanf("%d", &port);

    for (int i = port; i <= MAX_PORTS; i++)
    {
        scan_port(sockfd, i);
    }

    close(sockfd);

    return 0;
}

void scan_port(int sockfd, int port)
{
    struct sockaddr_in target_addr;
    int opt = 1;

    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    target_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&target_addr, sizeof(target_addr)) == 0)
    {
        printf("Port %d is open\n", port);
    }
    else
    {
        printf("Port %d is closed\n", port);
    }
}