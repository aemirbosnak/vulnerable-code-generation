//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

int main()
{
    system("clear");
    printf("-----------------------------------------------------------------------\n");
    printf("   /\_/\n"
           "  |||| | \n"
           "  \__) \n"
           "-----------------------------------------------------------------------\n");

    char hostname[256];
    printf("Enter hostname: ");
    scanf("%s", hostname);

    int sockfd = socket(AF_INET, SOCK_DGRAM, htons(53));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(53);
    inet_aton(hostname, &servaddr.sin_addr);

    char buf[1024];
    int len = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (len < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&servaddr, NULL);
    printf("Response: %s\n", buf);

    close(sockfd);
    system("clear");
    printf("-----------------------------------------------------------------------\n");
    printf("   /\_/\n"
           "  |||| | \n"
           "  \__) \n"
           "-----------------------------------------------------------------------\n");
    return 0;
}