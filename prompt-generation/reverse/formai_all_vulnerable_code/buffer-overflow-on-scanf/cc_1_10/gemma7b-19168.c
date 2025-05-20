//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, i, status, count = 0;
    char buf[1024], hostname[256];

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    port = 53;

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_aton(hostname, &servaddr.sin_addr);

    n = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    printf("Sent message: %s\n", buf);

    count = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, NULL);
    if (count < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received message: %s\n", buf);

    close(sockfd);

    return 0;
}