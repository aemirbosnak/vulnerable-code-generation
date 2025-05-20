//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: future-proof
#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PORT 65535

int main()
{
    int sockfd, port, n, err, host_fd;
    struct sockaddr_in sock_addr, host_addr;
    char buffer[1024];

    printf("Enter host IP address: ");
    scanf("%s", buffer);

    host_fd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (host_fd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    host_addr.sin_family = AF_INET;
    host_addr.sin_port = htons(80);
    host_addr.sin_addr.s_addr = inet_addr(buffer);

    connect(host_fd, (struct sockaddr *)&host_addr, sizeof(host_addr));

    printf("Enter port number: ");
    scanf("%d", &port);

    for (n = port; n <= MAX_PORT; n++)
    {
        sock_addr.sin_port = htons(n);
        sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        if (connect(sockfd, (struct sockaddr *)&host_addr, sizeof(host_addr)) == 0)
        {
            printf("Port %d is open\n", n);
            close(sockfd);
        }
    }

    close(host_fd);
    return 0;
}