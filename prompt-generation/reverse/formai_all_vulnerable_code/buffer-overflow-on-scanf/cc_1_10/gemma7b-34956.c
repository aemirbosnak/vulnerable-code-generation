//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_PINGS 10

int main()
{
    int sockfd, port, i, j, err, alive;
    char host[256];
    struct sockaddr_in server_addr;

    printf("Prepare for a shock!\n");
    printf("Enter the host name: ");
    scanf("%s", host);

    printf("Setting up the socket...\n");
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(65535));
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(1);
    }

    printf("Connecting to the server...\n");
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    err = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (err < 0)
    {
        perror("Connection error");
        exit(1);
    }

    printf("Sending pings...\n");
    for (i = 0; i < MAX_PINGS; i++)
    {
        char ping_msg[] = "PING!";
        send(sockfd, ping_msg, strlen(ping_msg), 0);

        alive = 0;
        for (j = 0; j < MAX_PINGS; j++)
        {
            char recv_msg[256];
            recv(sockfd, recv_msg, sizeof(recv_msg), 0);

            if (strcmp(recv_msg, "PONG!") == 0)
            {
                alive = 1;
                break;
            }
        }

        if (alive)
        {
            printf("Ping successful!\n");
        }
        else
        {
            printf("Ping failed!\n");
        }
    }

    close(sockfd);
    return 0;
}