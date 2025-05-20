//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "192.168.1.10"

int main()
{
    int sockfd, newsockfd, port, clientlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    time_t start_time, end_time;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Listening for connections
    listen(sockfd, &clientlen);

    // Client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);

    // Time measurement start
    start_time = time(NULL);

    // Data transfer
    read(newsockfd, buffer, 1024);
    write(newsockfd, buffer, 1024);

    // Time measurement end
    end_time = time(NULL);

    // Calculate uptime
    int uptime = (int)((end_time - start_time) * 100) / 60;

    // Print uptime
    printf("Uptime: %d minutes\n", uptime);

    // Close connections
    close(newsockfd);
    close(sockfd);

    return 0;
}