//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char hostname[256];
    char message[1024];
    int sockfd;
    struct sockaddr_in servaddr;
    int bytes_sent, bytes_received;
    int i, j;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(6);
    inet_aton(hostname, &servaddr.sin_addr);

    for (i = 0; i < 10; i++)
    {
        bytes_sent = send(sockfd, message, 1024, 0);
        if (bytes_sent < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        bytes_received = recv(sockfd, message, 1024, 0);
        if (bytes_received < 0)
        {
            perror("Error receiving message");
            exit(1);
        }

        printf("Received: %s\n", message);
    }

    close(sockfd);

    return 0;
}