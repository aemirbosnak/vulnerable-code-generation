//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, numbytes;
    char buffer[1025];
    struct hostent *he;
    struct sockaddr_in serveraddr;

    if (argc!= 2)
    {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    strcpy(buffer, argv[1]);
    he = gethostbyname(buffer);

    if (he == NULL)
    {
        printf("Error: could not resolve hostname\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error: could not create socket\n");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(7);

    inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)he->h_addr), &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1)
    {
        printf("Error: could not connect to server\n");
        exit(1);
    }

    send(sockfd, "PING", strlen("PING"), 0);

    while ((numbytes = recv(sockfd, buffer, 1024, 0)) > 0)
    {
        buffer[numbytes] = '\0';
        printf("%s", buffer);
    }

    if (numbytes == -1)
    {
        printf("Error: could not receive data\n");
        exit(1);
    }

    close(sockfd);

    return 0;
}