//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>

#define PORT_MIN 1
#define PORT_MAX 65535

int main()
{
    int port_num;
    char host_name[256];

    printf("Enter host name: ");
    scanf("%s", host_name);

    printf("Enter port number: ");
    scanf("%d", &port_num);

    struct sockaddr_in sock_addr;
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port_num);
    sock_addr.sin_addr.s_addr = inet_addr(host_name);

    int sockfd = socket(AF_INET, SOCK_STREAM, htons(5));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
    {
        perror("Error connecting to socket");
        exit(1);
    }

    char message[1024];
    printf("Enter message: ");
    scanf("%s", message);

    send(sockfd, message, strlen(message), 0);

    recv(sockfd, message, 1024, 0);

    printf("Received message: %s\n", message);

    close(sockfd);

    return 0;
}