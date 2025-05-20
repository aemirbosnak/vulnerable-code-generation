//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, i, n, count = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    n = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter the number of packets to send: ");
    scanf("%d", &count);

    for (i = 0; i < count; i++)
    {
        printf("Enter the packet data: ");
        scanf("%s", buffer);

        n = send(sockfd, buffer, 1024, 0);
        if (n < 0)
        {
            perror("Error sending packet");
            exit(1);
        }

        printf("Packet sent.\n");
    }

    close(sockfd);
    return 0;
}