//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

int main()
{
    int sockfd, port, n, i;
    char buf[1024], hostname[256];

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
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

    printf("Connection established.\n");

    // Exchange messages
    while (1)
    {
        printf("Enter your message: ");
        scanf("%s", buf);

        n = send(sockfd, buf, strlen(buf) + 1, 0);
        if (n < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        printf("Message sent.\n");

        n = recv(sockfd, buf, 1024, 0);
        if (n < 0)
        {
            perror("Error receiving message");
            exit(1);
        }

        printf("Received message: %s\n", buf);
    }

    close(sockfd);
    return 0;
}