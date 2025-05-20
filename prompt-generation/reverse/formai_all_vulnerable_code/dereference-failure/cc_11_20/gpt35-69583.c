//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BACKLOG 10
#define MAXLINE 4096

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
    {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    struct sockaddr_in proxy_addr, client_addr;
    bzero(&proxy_addr, sizeof(proxy_addr));
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listenfd, (struct sockaddr*)&proxy_addr, sizeof(proxy_addr)) < 0)
    {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listenfd, BACKLOG) < 0)
    {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    while(1)
    {
        socklen_t client_len = sizeof(client_addr);
        int clientfd = accept(listenfd, (struct sockaddr*)&client_addr, &client_len);
        if (clientfd < 0)
        {
            fprintf(stderr, "Error accepting request: %s\n", strerror(errno));
            continue;
        }

        char buffer[MAXLINE];
        bzero(&buffer, sizeof(buffer));
        int n = read(clientfd, buffer, sizeof(buffer)-1);
        if (n < 0)
        {
            fprintf(stderr, "Error reading from client socket: %s\n", strerror(errno));
            close(clientfd);
            continue;
        }

        char* hostname = strtok(buffer, " ");
        hostname = strtok(NULL, "/");
        if (!hostname)
        {
            fprintf(stderr, "Error parsing hostname from request\n");
            close(clientfd);
            continue;
        }

        char* path = strstr(buffer, "HTTP");
        if (!path)
        {
            fprintf(stderr, "Error parsing path from request\n");
            close(clientfd);
            continue;
        }

        int port = 80; // default port for HTTP
        char* portpos = strstr(hostname, ":");
        if (portpos)
        {
            *portpos = 0;
            port = atoi(portpos + 1);
        }

        struct hostent* server = gethostbyname(hostname);
        if (!server)
        {
            fprintf(stderr, "Error resolving hostname: %s\n", strerror(errno));
            close(clientfd);
            continue;
        }

        char address[MAXLINE];
        bzero(&address, sizeof(address));
        sprintf(address, "%s:%d", hostname, port);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
        {
            fprintf(stderr, "Error creating socket to remote server: %s\n", strerror(errno));
            close(clientfd);
            continue;
        }

        struct sockaddr_in server_addr;
        bzero(&server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        bcopy((char*)server->h_addr, (char*)&server_addr.sin_addr.s_addr, server->h_length);
        server_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        {
            fprintf(stderr, "Error connecting to remote server: %s\n", strerror(errno));
            close(clientfd);
            close(sockfd);
            continue;
        }

        if (write(sockfd, buffer, strlen(buffer)) < 0)
        {
            fprintf(stderr, "Error writing to remote server: %s\n", strerror(errno));
            close(clientfd);
            close(sockfd);
            continue;
        }

        bzero(&buffer, sizeof(buffer));
        while((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0)
        {
            if (write(clientfd, buffer, n) < 0)
            {
                fprintf(stderr, "Error writing to client socket: %s\n", strerror(errno));
                break;
            }

            bzero(&buffer, sizeof(buffer));
        }

        if (n < 0)
        {
            fprintf(stderr, "Error reading from remote server: %s\n", strerror(errno));
        }

        close(sockfd);
        close(clientfd);
    }

    return 0;
}