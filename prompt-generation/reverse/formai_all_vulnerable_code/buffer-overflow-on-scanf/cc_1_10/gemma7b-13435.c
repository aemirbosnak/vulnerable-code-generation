//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PINGS 10

int main()
{
    int i, ping_count = 0, success_count = 0;
    struct sockaddr_in server_addr;
    char server_ip[20];

    printf("Enter the server IP address: ");
    scanf("%s", server_ip);

    for (i = 0; i < MAX_PINGS; i++)
    {
        int sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
        if (sockfd == -1)
        {
            perror("Error creating socket");
            exit(1);
        }

        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(8080);
        inet_aton(server_ip, &server_addr.sin_addr);

        if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        {
            success_count++;
            printf("Ping successful!\n");
        }
        else
        {
            perror("Error connecting to server");
        }

        close(sockfd);
        ping_count++;
    }

    printf("Total pings: %d\n", ping_count);
    printf("Number of successful pings: %d\n", success_count);
    printf("Success rate: %.2f%%", (float)success_count / (float)ping_count * 100);

    return 0;
}