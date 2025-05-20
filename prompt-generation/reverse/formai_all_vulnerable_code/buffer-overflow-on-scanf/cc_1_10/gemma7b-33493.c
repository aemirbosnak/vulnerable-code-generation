//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n;
    char buf[1024];
    struct sockaddr_in serv_addr;

    printf("Enter the port number: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        return 1;
    }

    printf("Connection established.\n");

    n = read(sockfd, buf, 1024);
    if (n < 0)
    {
        perror("Error reading data");
        return 1;
    }

    printf("Received data: %s\n", buf);

    write(sockfd, "Hello, world!", 13);
    n = read(sockfd, buf, 1024);
    if (n < 0)
    {
        perror("Error reading data");
        return 1;
    }

    printf("Received data: %s\n", buf);

    close(sockfd);
    return 0;
}