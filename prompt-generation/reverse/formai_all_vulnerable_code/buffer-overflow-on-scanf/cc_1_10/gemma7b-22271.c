//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char hostname[256];
    char port[6];
    int sockfd, portnum, err, i, n;
    struct sockaddr_in serv_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%s", port);

    portnum = atoi(port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(portnum));

    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portnum);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established.\n");

    n = 0;
    while (n < 10)
    {
        char buf[1024];

        printf("Enter message: ");
        scanf("%s", buf);

        send(sockfd, buf, strlen(buf) + 1, 0);

        n++;
    }

    close(sockfd);

    return 0;
}