//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: brave
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd, port, n;
    char buf[1024], hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_aton(hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter message: ");
    scanf("%s", buf);

    n = write(sockfd, buf, strlen(buf) + 1);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    n = read(sockfd, buf, 1024);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received message: %s", buf);

    close(sockfd);

    return 0;
}