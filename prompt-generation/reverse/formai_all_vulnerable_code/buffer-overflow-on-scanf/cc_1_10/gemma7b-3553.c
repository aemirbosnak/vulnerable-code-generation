//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, j, num_pings, status;
    char hostname[256];
    struct sockaddr_in server_addr;
    int sockfd, recv_len;
    char recv_buffer[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    num_pings = 0;
    while (num_pings < MAX_PINGS)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
        if (sockfd < 0)
        {
            perror("Error creating socket");
            exit(1);
        }

        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(80);
        server_addr.sin_addr.s_addr = inet_addr(hostname);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        {
            perror("Error connecting to server");
            close(sockfd);
            continue;
        }

        recv_len = recv(sockfd, recv_buffer, 1024, 0);
        if (recv_len > 0)
        {
            printf("Received: %s\n", recv_buffer);
            num_pings++;
        }

        close(sockfd);
    }

    return 0;
}