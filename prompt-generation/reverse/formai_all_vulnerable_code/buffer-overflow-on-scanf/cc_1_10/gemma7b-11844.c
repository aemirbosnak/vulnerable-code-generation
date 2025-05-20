//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int sockfd, n, err, host_num;
    char hostname[256], buf[1024], ping_reply[1024], *ptr;

    printf("Enter the hostname or IP address: ");
    scanf("%s", hostname);

    host_num = gethostbyname(hostname);
    if (host_num == -1)
    {
        printf("Error: invalid hostname.\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, htons(5));
    if (sockfd < 0)
    {
        printf("Error: socket creation failed.\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(6);
    server_addr.sin_addr.s_addr = host_num;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: connection failed.\n");
        return 1;
    }

    printf("Enter your message: ");
    scanf("%[^\n]%*c", buf);

    send(sockfd, buf, strlen(buf) + 1, 0);

    n = recv(sockfd, ping_reply, 1024, 0);

    ptr = ping_reply;

    printf("Received reply: ");
    while (*ptr)
    {
        printf("%c ", *ptr);
        ptr++;
    }

    printf("\n");

    close(sockfd);

    return 0;
}