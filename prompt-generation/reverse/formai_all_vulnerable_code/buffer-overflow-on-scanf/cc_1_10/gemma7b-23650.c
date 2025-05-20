//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, srvsockfd, port, n;
    char buf[1024];

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return -1;
    }

    srvsockfd = listen(sockfd, 10);
    if (srvsockfd < 0)
    {
        perror("Error listening on socket");
        return -1;
    }

    printf("Server listening on port %d...\n", port);

    for (;;)
    {
        n = recvfrom(srvsockfd, buf, 1024, 0, NULL, NULL);
        if (n < 0)
        {
            perror("Error receiving data");
            return -1;
        }

        printf("Client: %s\n", buf);

        n = sendto(sockfd, buf, n, 0, NULL, NULL);
        if (n < 0)
        {
            perror("Error sending data");
            return -1;
        }

        printf("Server: %s\n", buf);
    }

    close(sockfd);
    close(srvsockfd);

    return 0;
}