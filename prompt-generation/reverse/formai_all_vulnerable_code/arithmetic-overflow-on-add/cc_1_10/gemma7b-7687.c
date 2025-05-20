//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PORT_RANGE 1024

int main()
{
    int sockfd, newsockfd, port, i, j, k, timeout = 1, scan_start, scan_end;
    struct sockaddr_in server_addr, client_addr;
    char buffer[4096], hostname[256];
    time_t start_time, end_time, elapsed_time;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter scan start port: ");
    scanf("%d", &scan_start);

    printf("Enter scan end port: ");
    scanf("%d", &scan_end);

    start_time = time(NULL);

    for (port = scan_start; port <= scan_end; port++)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

        if (sockfd < 0)
        {
            perror("Error creating socket");
            continue;
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        close(sockfd);
    }

    end_time = time(NULL);
    elapsed_time = end_time - start_time;

    printf("Total time elapsed: %ld seconds\n", elapsed_time);

    return 0;
}