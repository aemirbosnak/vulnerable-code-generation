//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define SERVER_PORT 8080

int main()
{
    char hostname[256];
    struct sockaddr_in server_addr;
    int sockfd, ret, i, k;
    time_t start, end;
    double elapsed_time;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_aton(hostname, &server_addr.sin_addr);

    start = time(NULL);
    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0)
    {
        perror("Error connecting to server");
        close(sockfd);
        exit(1);
    }

    end = time(NULL);
    elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Connection established. Ping time: %.3f seconds\n", elapsed_time);

    for (i = 0; i < 10; i++)
    {
        char message[256];
        printf("Enter message: ");
        scanf("%s", message);

        k = send(sockfd, message, sizeof(message), 0);
        if (k < 0)
        {
            perror("Error sending message");
            close(sockfd);
            exit(1);
        }

        k = recv(sockfd, message, sizeof(message), 0);
        if (k < 0)
        {
            perror("Error receiving message");
            close(sockfd);
            exit(1);
        }

        printf("Received message: %s\n", message);
    }

    close(sockfd);
    return 0;
}