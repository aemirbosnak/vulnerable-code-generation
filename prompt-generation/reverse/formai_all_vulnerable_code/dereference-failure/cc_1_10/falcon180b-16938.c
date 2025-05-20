//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct hostent *host;
    struct sockaddr_in serv_addr;
    char *ip_address;
    int port;
    char buffer[1025];

    if (argc!= 4)
    {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(1);
    }

    ip_address = argv[1];
    port = atoi(argv[2]);

    if ((host = gethostbyname(ip_address)) == NULL)
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = *(unsigned long *)host->h_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    printf("Connected to %s:%d\n", ip_address, port);

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));

        if (n <= 0)
        {
            printf("Disconnected\n");
            break;
        }

        printf("Received: %s", buffer);
    }

    close(sockfd);
    return 0;
}