//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX 10

struct sockaddr_in serv_addr;
int sockfd[MAX];
char ip[16];

void scan(int start_port, int end_port)
{
    int sport;
    for(sport=start_port; sport<=end_port; sport++)
    {
        sockfd[sport] = socket(AF_INET, SOCK_STREAM, 0);
        if(sockfd[sport] < 0)
        {
            printf("Error creating socket\n");
            exit(0);
        }

        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(sport);
        inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

        if(connect(sockfd[sport], (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
        {
            printf("Port %d is closed\n", sport);
        }
        else
        {
            printf("Port %d is open\n", sport);
            close(sockfd[sport]);
        }
    }
}

int main()
{
    int start_port, end_port;
    printf("Enter start port: ");
    scanf("%d", &start_port);
    printf("Enter end port: ");
    scanf("%d", &end_port);

    scan(start_port, end_port);

    return 0;
}