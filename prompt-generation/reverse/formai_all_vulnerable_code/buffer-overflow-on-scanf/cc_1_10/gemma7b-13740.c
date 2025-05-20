//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: rigorous
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
    int sockfd, i, n, err, status;
    struct sockaddr_in servaddr;

    printf("Enter the hostname of the server: ");
    scanf("%s", hostname);

    printf("Enter the message to be sent: ");
    scanf("%s", message);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    n = write(sockfd, message, sizeof(message));
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    status = read(sockfd, message, sizeof(message));
    if (status < 0)
    {
        perror("Error reading response");
        exit(1);
    }

    printf("Received response: %s\n", message);

    close(sockfd);

    return 0;
}