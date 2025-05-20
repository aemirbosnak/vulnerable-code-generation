//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char host[256];
    int port = 53;
    int sockfd, err, status;
    struct sockaddr_in srv_addr;

    printf("Enter host name: ");
    scanf("%s", host);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    inet_aton(host, &srv_addr.sin_addr);

    status = connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    if (status < 0)
    {
        perror("Error connecting");
        exit(1);
    }

    printf("Connection established.\n");

    char msg[1024];
    printf("Enter message: ");
    scanf("%s", msg);

    send(sockfd, msg, strlen(msg), 0);

    recv(sockfd, msg, 1024, 0);

    printf("Received message: %s\n", msg);

    close(sockfd);

    return 0;
}