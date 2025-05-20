//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    if (argc!= 2)
    {
        printf("Usage: %s <proxy-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int proxy_port = atoi(argv[1]);
    int server_port = 8080;

    struct addrinfo hints, *res, *rp;
    int sockfd;
    int optval = 1;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("localhost", "80", &hints, &res);
    for (rp = res; rp!= NULL; rp = rp->ai_next)
    {
        if (rp->ai_family == AF_INET)
        {
            sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
            break;
        }
    }

    if (sockfd == -1)
    {
        printf("Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof optval);

    if (bind(sockfd, rp->ai_addr, rp->ai_addrlen) == -1)
    {
        printf("Failed to bind socket\n");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(res);

    while (1)
    {
        int client_sockfd = accept(sockfd, NULL, NULL);
        if (client_sockfd == -1)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        int request_size = recv(client_sockfd, NULL, 0, 0);
        if (request_size == -1)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        char *request_buffer = malloc(request_size);
        if (request_buffer == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        int received = recv(client_sockfd, request_buffer, request_size, 0);
        if (received == -1)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        if (strcmp(request_buffer, "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n") == 0)
        {
            int server_sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
            if (server_sockfd == -1)
            {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            if (connect(server_sockfd, rp->ai_addr, rp->ai_addrlen) == -1)
            {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            char response_buffer[1024];
            memset(response_buffer, 0, sizeof response_buffer);
            int response_size = send(server_sockfd, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>", strlen("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body>Hello, World!</body></html>"), 0);
            if (response_size == -1)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }

            int sent = send(client_sockfd, response_buffer, response_size, 0);
            if (sent == -1)
            {
                perror("send");
                exit(EXIT_FAILURE);
            }

            close(client_sockfd);
            close(server_sockfd);
            break;
        }

        free(request_buffer);
        close(client_sockfd);
    }

    close(sockfd);

    return 0;
}