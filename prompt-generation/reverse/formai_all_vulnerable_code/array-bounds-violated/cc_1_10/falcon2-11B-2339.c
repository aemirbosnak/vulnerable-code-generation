//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: Linus Torvalds
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <pthread.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[1024];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(80);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1)
    {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        portno = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (portno == -1)
        {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        while ((n = recv(portno, buffer, 1024, 0)) > 0)
        {
            buffer[n] = '\0';
            printf("Received: %s\n", buffer);
            send(portno, buffer, strlen(buffer), 0);
        }

        close(portno);
    }

    close(sockfd);
    return 0;
}