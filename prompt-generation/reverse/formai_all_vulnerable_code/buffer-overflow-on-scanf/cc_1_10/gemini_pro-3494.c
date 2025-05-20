//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main()
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[BUF_SIZE], message[BUF_SIZE];
    int n;

    printf("Huzzah! Welcome to thy humble chat server, good travelers.\n");
    printf("What port shall we listen upon, good sir? ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Socket creation failed, alas!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr, cli_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Bind failed, woe is me!");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) < 0)
    {
        perror("Listen failed, the ravens are silent!");
        exit(EXIT_FAILURE);
    }

    printf("Awaiting any brave soul to join the conversation.\n");

    while (1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
        {
            perror("Accept failed, the gates are barred!");
            exit(EXIT_FAILURE);
        }

        printf("Huzzah! A fellow traveler has joined us!\n");

        while (1)
        {
            memset(buffer, 0, BUF_SIZE);
            n = read(newsockfd, buffer, BUF_SIZE);
            if (n < 0)
            {
                perror("Read failed, the scroll is empty!");
                exit(EXIT_FAILURE);
            }
            else if (n == 0)
            {
                printf("Farewell, good sir! May your travels be filled with adventure.\n");
                close(newsockfd);
                break;
            }

            printf("Message received: %s\n", buffer);

            memset(message, 0, BUF_SIZE);
            printf("Enter thy response, good sir: ");
            fgets(message, BUF_SIZE, stdin);

            n = write(newsockfd, message, strlen(message));
            if (n < 0)
            {
                perror("Write failed, the quill is broken!");
                exit(EXIT_FAILURE);
            }
        }
    }

    close(sockfd);

    return 0;
}