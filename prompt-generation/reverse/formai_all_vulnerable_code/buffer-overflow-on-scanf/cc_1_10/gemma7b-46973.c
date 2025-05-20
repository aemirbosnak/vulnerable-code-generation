//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd, port, n, len, status;
    struct sockaddr_in server_addr;
    char buf[1024];
    char hostname[256];

    printf("Please enter the hostname: ");
    scanf("%s", hostname);

    port = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (status == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to server at %s:%d\n", hostname, port);

    n = read(sockfd, buf, 1024);
    if (n > 0)
    {
        printf("Server says: %s\n", buf);
    }

    write(sockfd, "Hello, world!", 13);

    n = read(sockfd, buf, 1024);
    if (n > 0)
    {
        printf("Server says: %s\n", buf);
    }

    close(sockfd);
    exit(0);
}