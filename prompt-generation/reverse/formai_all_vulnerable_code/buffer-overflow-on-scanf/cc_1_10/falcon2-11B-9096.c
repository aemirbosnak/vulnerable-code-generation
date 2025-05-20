//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    int sockfd, port, n;
    struct sockaddr_in servaddr;

    /* create a socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    /* fill in the sockaddr_in structure */
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr.s_addr = inet_addr("192.168.0.1");

    /* connect to the server */
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection successful\n");

    while (1)
    {
        printf("Enter the port number: ");
        scanf("%d", &port);

        if (port <= 0 || port > 65535)
        {
            printf("Invalid port number\n");
            continue;
        }

        if (port == 80)
        {
            printf("Port 80 is open\n");
        }
        else
        {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);
    return 0;
}