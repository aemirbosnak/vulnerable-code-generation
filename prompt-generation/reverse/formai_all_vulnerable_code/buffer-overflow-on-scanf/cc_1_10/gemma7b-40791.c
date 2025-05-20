//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, i, srv_sockfd, client_sockfd;
    char buf[1024];
    struct sockaddr_in srv_addr, client_addr;
    char hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port: ");
    scanf("%d", &port);

    srv_sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (srv_sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    memset(&srv_addr, 0, sizeof(srv_addr));
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(port);
    srv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (bind(srv_sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    printf("Server listening on port %d\n", port);

    while (1)
    {
        client_sockfd = accept(srv_sockfd, (struct sockaddr *)&client_addr, NULL);
        if (client_sockfd < 0)
        {
            perror("Error accepting connection");
            continue;
        }

        n = read(client_sockfd, buf, 1024);
        if (n < 0)
        {
            perror("Error reading data");
            close(client_sockfd);
            continue;
        }

        printf("Client: %s\n", buf);

        write(client_sockfd, buf, n);

        close(client_sockfd);
    }

    return 0;
}