//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: inquisitive
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd, port, n, i, j, k, flag = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024], message[1024], hostname[256];

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    port = 50001;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, htons(port))) < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    n = sendto(sockfd, message, 1024, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    k = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&serv_addr, NULL);

    if (k < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}