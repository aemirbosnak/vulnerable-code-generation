//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char hostname[256];
    char port[6];
    int sockfd;
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%s", port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s on port %s\n", hostname, port);

    char message[1024];
    printf("Enter message: ");
    scanf("%s", message);

    send(sockfd, message, strlen(message), 0);

    char reply[1024];
    recv(sockfd, reply, 1024, 0);

    printf("Reply: %s\n", reply);

    close(sockfd);

    return 0;
}