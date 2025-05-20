//Gemma-7B DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

int main()
{

    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error binding socket");
        exit(1);
    }

    char buf[1024];
    int nread;

    while (1)
    {
        nread = recv(sockfd, buf, 1024, 0);
        if (nread == -1)
        {
            perror("Error receiving data");
            exit(1);
        }

        if (nread == 0)
        {
            printf("Client disconnected\n");
            break;
        }

        buf[nread] = '\0';
        printf("Received: %s\n", buf);

        nread = send(sockfd, buf, strlen(buf) + 1, 0);
        if (nread == -1)
        {
            perror("Error sending data");
            exit(1);
        }

        printf("Sent: %s\n", buf);
    }

    close(sockfd);
    return 0;
}