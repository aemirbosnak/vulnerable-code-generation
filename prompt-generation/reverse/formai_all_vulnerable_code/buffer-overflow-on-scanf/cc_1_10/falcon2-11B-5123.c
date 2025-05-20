//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    char message[100];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    printf("Please enter the IP address of the other player: ");
    scanf("%s", message);

    if (send(sockfd, message, strlen(message), 0) < 0)
    {
        perror("ERROR sending message");
        exit(EXIT_FAILURE);
    }

    bzero(message, 100);
    n = recv(sockfd, message, 100, 0);
    if (n < 0)
    {
        perror("ERROR receiving message");
        exit(EXIT_FAILURE);
    }

    printf("Received message from the other player: %s\n", message);

    close(sockfd);
    return 0;
}