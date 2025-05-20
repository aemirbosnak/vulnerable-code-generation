//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: Claude Shannon
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    int sockfd, port, n, i, data_len, flag = 0;
    char buf[1024], msg[256], hostname[256];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    port = 53000;
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        return 1;
    }

    printf("Enter message: ");
    scanf("%s", msg);

    data_len = strlen(msg) + 1;
    write(sockfd, msg, data_len);

    n = read(sockfd, buf, 1024);

    if (n < 0)
    {
        perror("Error reading from server");
        return 1;
    }

    buf[n] = '\0';

    printf("Server's response: %s\n", buf);

    close(sockfd);
    return 0;
}