//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define PORT_SCAN_DELAY 0.05

int main()
{
    int sockfd, port, n, host_port, scan_start, scan_end, i, flag = 0;
    char hostname[256], buf[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter scan start port: ");
    scanf("%d", &scan_start);

    printf("Enter scan end port: ");
    scanf("%d", &scan_end);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(2));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    for (port = scan_start; port <= scan_end; port++)
    {
        struct sockaddr_in srv_addr;
        srv_addr.sin_family = AF_INET;
        srv_addr.sin_port = htons(port);
        srv_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == 0)
        {
            printf("Port %d is open.\n", port);
            flag = 1;
        }

        sleep(PORT_SCAN_DELAY);
    }

    if (!flag)
    {
        printf("No ports are open.\n");
    }

    close(sockfd);

    return 0;
}