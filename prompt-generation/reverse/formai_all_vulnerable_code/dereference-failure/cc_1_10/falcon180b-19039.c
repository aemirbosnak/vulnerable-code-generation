//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (argc!= 3)
    {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    if (sockfd == -1)
    {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server: %s\n", strerror(errno));
        close(sockfd);
        exit(1);
    }

    printf("Connected to server\n");

    while (1)
    {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0)
        {
            printf("Error receiving data: %s\n", strerror(errno));
            close(sockfd);
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}