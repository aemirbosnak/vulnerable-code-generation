//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    char host[256];
    int port = 53;
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *hp;

    printf("Enter the host name: ");
    scanf("%s", host);

    hp = gethostbyname(host);
    if (hp == NULL)
    {
        perror("gethostbyname");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = hp->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    printf("Ping! Echo: ");
    char buf[1024];
    recv(sockfd, buf, 1024, 0);
    printf("%s\n", buf);

    close(sockfd);

    return 0;
}