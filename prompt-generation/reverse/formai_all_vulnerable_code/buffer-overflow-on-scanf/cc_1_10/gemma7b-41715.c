//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, i, j, k, l, m, addr_len;
    char buf[1024], hostname[256], message[1024];
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_aton(hostname, &servaddr.sin_addr);

    addr_len = sizeof(servaddr);

    connect(sockfd, (struct sockaddr *)&servaddr, addr_len);

    printf("Enter your message: ");
    scanf("%s", message);

    send(sockfd, message, strlen(message), 0);

    n = recv(sockfd, buf, 1024, 0);

    if (n > 0)
    {
        printf("Received message: %s", buf);
    }

    close(sockfd);

    return 0;
}