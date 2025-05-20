//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: recursive
#include <stdio.h>
#include <netdb.h>

void scan(char *hostname, int port)
{
    int sockfd, n, err;
    struct sockaddr_in serv_addr;
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd == -1)
    {
        perror("Error opening socket");
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to socket");
        close(sockfd);
        return;
    }

    n = read(sockfd, buffer, 1024);
    if (n > 0)
    {
        printf("Port %d: %s\n", port, buffer);
    }

    close(sockfd);
    scan(hostname, port + 1);
}

int main()
{
    char *hostname;
    int port;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    scan(hostname, port);

    return 0;
}