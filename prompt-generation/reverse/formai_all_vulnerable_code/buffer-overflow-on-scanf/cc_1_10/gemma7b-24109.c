//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in srv_addr;
    srv_addr.sin_family = AF_INET;
    srv_addr.sin_port = htons(80);
    srv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    while (1)
    {
        printf("Enter a command: ");
        scanf("%s", buffer);

        if (strcmp(buffer, "quit") == 0)
        {
            break;
        }

        send(sockfd, buffer, strlen(buffer) + 1, 0);

        bytes_read = recv(sockfd, buffer, 1024, 0);

        if (bytes_read > 0)
        {
            printf("Server response: %s\n", buffer);
        }
    }

    close(sockfd);
    return 0;
}