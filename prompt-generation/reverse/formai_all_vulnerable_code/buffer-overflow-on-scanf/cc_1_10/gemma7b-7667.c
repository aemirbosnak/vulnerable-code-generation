//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main()
{
    char hostname[256];
    char port[6];
    int sockfd;
    struct sockaddr_in servaddr;
    int n;
    char buffer[BUFFER_SIZE];

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

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    inet_aton(hostname, &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0)
    {
        perror("Error reading from server");
        exit(1);
    }

    printf("Received data: %s", buffer);

    close(sockfd);

    return 0;
}