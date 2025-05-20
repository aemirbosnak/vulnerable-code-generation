//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: visionary
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT_MIN 0
#define PORT_MAX 65535

void scan(char *hostname, int port)
{
    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *hp;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, htons(port))) < 0)
    {
        perror("Error creating socket");
        return;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to socket");
        close(sockfd);
        return;
    }

    hp = gethostbyaddr(&servaddr.sin_addr.s_addr, sizeof(servaddr.sin_addr), AF_INET);

    printf("Host: %s, Port: %d\n", hp->h_name, port);

    close(sockfd);
}

int main()
{
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    int port = atoi(stdin);

    scan(hostname, port);

    return 0;
}