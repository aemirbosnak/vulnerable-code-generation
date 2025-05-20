//Gemma-7B DATASET v1.0 Category: Networking ; Style: Donald Knuth
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[1024];
    int n;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(1);
    }

    // Server address setup
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Connect error");
        exit(1);
    }

    // Send and receive messages
    while (1)
    {
        printf("Enter a message: ");
        scanf("%s", buf);
        n = strlen(buf) + 1;
        send(sockfd, buf, n, 0);

        // Receive message
        recv(sockfd, buf, 1024, 0);
        printf("Received: %s\n", buf);

        // Check if the client wants to quit
        if (strcmp(buf, "quit") == 0)
        {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}