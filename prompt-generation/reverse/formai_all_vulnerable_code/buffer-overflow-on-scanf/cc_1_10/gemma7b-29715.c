//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, port, n, i;
    char hostname[256];
    struct sockaddr_in server_addr;
    char buffer[1024];
    char ping_message[] = "PING!";
    char reply_message[1024];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    port = 8080;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    n = write(sockfd, ping_message, strlen(ping_message));
    if (n < 0)
    {
        perror("Error sending ping message");
        exit(1);
    }

    n = read(sockfd, reply_message, 1024);
    if (n < 0)
    {
        perror("Error reading reply message");
        exit(1);
    }

    printf("Reply: %s\n", reply_message);

    close(sockfd);
    return 0;
}