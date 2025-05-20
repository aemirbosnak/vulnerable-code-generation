//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define BUF_SIZE 1024
#define PORT 8080
#define BACKLOG 10

int main()
{
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int n, addrlen;
    time_t start_time, end_time;
    double elapsed_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, BACKLOG) == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while(1)
    {
        addrlen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &addrlen);

        if (newsockfd == -1)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        start_time = time(NULL);
        while(1)
        {
            memset(buffer, 0, BUF_SIZE);
            n = recv(newsockfd, buffer, BUF_SIZE, 0);

            if (n == 0)
            {
                printf("Client disconnected\n");
                close(newsockfd);
                break;
            }

            buffer[n] = '\0';
            printf("Received message: %s\n", buffer);

            send(newsockfd, buffer, n, 0);
        }

        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);
        printf("Connection closed after %lf seconds\n", elapsed_time);
    }

    close(sockfd);
    return 0;
}