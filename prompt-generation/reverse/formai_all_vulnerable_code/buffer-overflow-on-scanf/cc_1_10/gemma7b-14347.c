//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main()
{
    int sockfd, n, host_port, target_port;
    char hostname[256], buffer[1024];
    struct sockaddr_in server_addr;

    printf("Enter hostname: ");
    scanf("%s", hostname);
    printf("Enter target port: ");
    scanf("%d", &target_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(target_port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to %s on port %d\n", hostname, target_port);

    n = read(sockfd, buffer, 1024);
    if (n > 0)
    {
        printf("Received data: %s\n", buffer);
    }

    write(sockfd, "Hello, world!", 13);
    n = read(sockfd, buffer, 1024);
    if (n > 0)
    {
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);
    exit(0);
}