//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define SERVER_PORT 8080
#define MONITOR_INTERVAL 60

int main()
{
    time_t last_check = time(NULL);
    int sockfd, clientfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];

    // Bind socket to port
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_family = AF_INET;
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for clients
    while (1)
    {
        clientfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

        // Check if enough time has passed since last check
        if (time(NULL) - last_check >= MONITOR_INTERVAL)
        {
            // Send uptime/downtime message to client
            sprintf(buffer, "Uptime: %d", is_website_up("example.com"));
            send(clientfd, buffer, strlen(buffer), 0);

            last_check = time(NULL);
        }

        close(clientfd);
    }
}

int is_website_up(char *url)
{
    int sockfd, port = 80;
    struct sockaddr_in server_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(url);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
    {
        close(sockfd);
        return 1;
    }

    close(sockfd);
    return 0;
}