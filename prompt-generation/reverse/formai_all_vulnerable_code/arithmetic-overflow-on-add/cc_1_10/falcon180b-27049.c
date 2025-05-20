//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: cheerful
// C Port Scanner Program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>

#define MAX 100

void scan(int sockfd, struct sockaddr_in serv_addr, int port)
{
    if(connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        printf("\n Port %d is not open", port);
    }
    else
    {
        printf("\n Port %d is open", port);
    }
}

int main()
{
    int sockfd, newsockfd, portno, clilen, i;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    printf("\n Enter the IP address: ");
    scanf("%s", buffer);

    printf("\n Enter the range of ports to scan (e.g. 1-100): ");
    scanf("%s", buffer);

    sscanf(buffer, "%d-%d", &portno, &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd == -1)
    {
        printf("\n Socket creation failed");
        exit(0);
    }

    for(i=portno; i<=portno; i++)
    {
        printf("\n Scanning port %d", i);
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clilen);

        if(newsockfd == -1)
        {
            printf("\n Port %d is closed", i);
        }
        else
        {
            close(newsockfd);
            printf("\n Port %d is open", i);
        }
    }

    close(sockfd);
    return 0;
}

// End of C Port Scanner Program