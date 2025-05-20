//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: creative
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_PORTS 65535

int main()
{
    int sockfd, port, n, err, target_port;
    char buf[1024];
    struct sockaddr_in servaddr;

    printf("Enter target IP: ");
    scanf("%s", buf);

    printf("Enter target port: ");
    scanf("%d", &target_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(2));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(target_port);
    servaddr.sin_addr.s_addr = inet_addr(buf);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter command: ");
    scanf("%s", buf);

    write(sockfd, buf, strlen(buf) + 1);

    n = read(sockfd, buf, 1024);
    if (n > 0)
    {
        printf("Server response: %s", buf);
    }

    close(sockfd);
    exit(0);
}