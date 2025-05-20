//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, i, recv_len, send_len;
    char buf[4096];
    struct sockaddr_in serv_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    printf("Listening on port %d...\n", port);

    while (1)
    {
        recv_len = recv(sockfd, buf, 4096, 0);
        if (recv_len > 0)
        {
            send_len = send(sockfd, buf, recv_len, 0);
            if (send_len < 0)
            {
                perror("Error sending data");
            }
        }
        else if (recv_len == 0)
        {
            printf("Client disconnected.\n");
        }
        else
        {
            perror("Error receiving data");
        }
    }

    close(sockfd);
    return 0;
}