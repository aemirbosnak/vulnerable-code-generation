//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    int sockfd, port, n, i, status, timo, timeout, recvd_bytes, flag = 0;
    char hostname[256], buf[4096], ping_msg[] = "PING", pong_msg[] = "PONG";

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    timo = 1;
    timeout = timo * 1000;

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    send(sockfd, ping_msg, strlen(ping_msg), 0);
    recvd_bytes = recv(sockfd, buf, sizeof(buf), 0);

    if (recvd_bytes > 0)
    {
        printf("Received: %s\n", buf);

        if (strcmp(buf, pong_msg) == 0)
        {
            printf("Connection successful!\n");
            flag = 1;
        }
    }

    close(sockfd);

    if (flag == 0)
    {
        printf("Connection failed!\n");
    }

    return 0;
}