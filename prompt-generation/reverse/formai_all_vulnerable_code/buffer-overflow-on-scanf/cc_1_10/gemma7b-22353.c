//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_SLEEP_TIME 5

int main()
{
    int sockfd, n, port, i, status;
    char hostname[256];
    struct sockaddr_in server_addr;
    struct timeval tv_start, tv_end, diff;
    time_t start_time, end_time;

    printf("Please enter the hostname of the server: ");
    scanf("%s", hostname);

    printf("Please enter the port number of the server: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_DGRAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    start_time = time(NULL);
    tv_start.tv_sec = start_time;
    tv_start.tv_usec = 0;

    n = sendto(sockfd, "PING", 4, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

    end_time = time(NULL);
    tv_end.tv_sec = end_time;
    tv_end.tv_usec = 0;

    diff.tv_sec = tv_end.tv_sec - tv_start.tv_sec;
    diff.tv_usec = tv_end.tv_usec - tv_start.tv_usec;

    status = recvfrom(sockfd, "RESPONSE", 4, 0, (struct sockaddr *)&server_addr, NULL);

    if (status > 0)
    {
        printf("The server responded: %s\n", "RESPONSE");
    }
    else
    {
        perror("Error receiving response");
    }

    close(sockfd);

    return 0;
}