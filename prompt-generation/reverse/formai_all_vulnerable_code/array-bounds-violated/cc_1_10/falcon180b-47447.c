//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct addrinfo *server_info;
    struct addrinfo hints;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", "8080", &hints, &server_info)!= 0)
    {
        fprintf(stderr, "Error: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(server_info->ai_family, server_info->ai_socktype, server_info->ai_protocol);

    if (sockfd == -1)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1)
    {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        exit(1);
    }

    while (1)
    {
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0)
        {
            fprintf(stderr, "Error: %s\n", strerror(errno));
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sockfd);
    freeaddrinfo(server_info);

    return 0;
}