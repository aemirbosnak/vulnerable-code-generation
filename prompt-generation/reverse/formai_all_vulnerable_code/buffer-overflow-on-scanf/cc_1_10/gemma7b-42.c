//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

int main()
{
    int sockfd, port, n, i, host_num;
    char hostname[256];

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_aton(hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connection established.\n");

    n = write(sockfd, "Hello, world!", 13);
    if (n == -1)
    {
        perror("Error sending message");
        exit(1);
    }

    n = read(sockfd, hostname, 256);
    if (n == -1)
    {
        perror("Error receiving message");
        exit(1);
    }

    printf("Received: %s\n", hostname);

    close(sockfd);

    return 0;
}