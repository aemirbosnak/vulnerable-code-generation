//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Welcome to the C Network Ping Test!\n");
    printf("Please enter the hostname or IP address: ");
    char hostname[256];
    scanf("%s", hostname);

    struct hostent *hp;
    struct servent *sp;
    int sockfd, port = 8080;
    char buffer[1024];

    hp = gethostbyname(hostname);
    if (hp == NULL)
    {
        perror("Error getting host information");
        exit(1);
    }

    sp = getservbyport(port, hp->h_name);
    if (sp == NULL)
    {
        perror("Error getting service information");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, htons(sp->s_port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *)hp->h_addr, sizeof(struct sockaddr));

    printf("Sending data...\n");
    write(sockfd, "Hello, world!", 13);

    printf("Receiving data...\n");
    read(sockfd, buffer, 1024);

    printf("Data received: %s\n", buffer);

    close(sockfd);
    exit(0);
}