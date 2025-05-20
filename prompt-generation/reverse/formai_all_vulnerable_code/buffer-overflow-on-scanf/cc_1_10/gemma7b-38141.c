//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#define PORT_RANGE 1024

int main()
{
    int sockfd, port, n, err, host_port;
    char buf[1024];
    struct sockaddr_in server_addr;

    printf("Enter host IP address: ");
    scanf("%s", buf);

    printf("Enter port range (e.g. 1-1024): ");
    scanf("%d-%d", &port, &host_port);

    port = atoi(buf);
    host_port = atoi(buf);

    for (port = port; port <= host_port; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(buf);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        n = read(sockfd, buf, 1024);

        if (n > 0)
        {
            printf("Port %d: Received data: %s\n", port, buf);
        }

        close(sockfd);
    }

    return 0;
}