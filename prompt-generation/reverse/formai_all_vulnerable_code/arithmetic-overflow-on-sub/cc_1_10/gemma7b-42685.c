//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080

int main()
{
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    char buf[1024];
    time_t start_time, end_time, uptime;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Measure uptime
    start_time = time(NULL);

    // Send and receive data
    n = send(sockfd, "Hello, world!", 13, 0);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    n = recv(sockfd, buf, 1024, 0);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    end_time = time(NULL);
    uptime = end_time - start_time;

    // Print uptime
    printf("Uptime: %ld seconds\n", uptime);

    // Close socket
    close(sockfd);

    return 0;
}