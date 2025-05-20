//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>

#define MAX_CONNECTIONS 1024 // maximum number of connections to handle at a time
#define BUFFER_SIZE 1024 // maximum buffer size for the request and response

int main(int argc, char *argv[])
{
    int sockfd, new_sockfd; // server and client socket descriptors
    socklen_t clilen;
    char buffer[BUFFER_SIZE], response[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    if (argc < 2)
    {
        fprintf(stderr,"usage %s port\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("ERROR opening socket");
        exit(1);
    }

    int enable = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    {
        perror("setsockopt(SO_REUSEADDR) failed");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    int portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, MAX_CONNECTIONS) < 0)
    {
        perror("ERROR on listen");
        exit(1);
    }

    printf("HTTP proxy is running on port %d\n", portno);

    while(1)
    {
        clilen = sizeof(cli_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (new_sockfd < 0)
        {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New client connected from %s:%d\n",inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        bzero(buffer, BUFFER_SIZE);
        bzero(response, BUFFER_SIZE);

        int n = read(new_sockfd, buffer, BUFFER_SIZE);

        if (n < 0)
        {
            perror("ERROR reading from socket");
            exit(1);
        }

        printf("Request received from client:\n%s\n\n", buffer);

        char *url_start = strstr(buffer, "://");

        if (url_start == NULL)
        {
            printf("Invalid HTTP request\n");
            continue;
        }

        url_start += 3;

        char *url_end = strstr(url_start, " ");

        if (url_end == NULL)
        {
            printf("Invalid HTTP request\n");
            continue;
        }

        char url[BUFFER_SIZE], hostname[BUFFER_SIZE];
        strncpy(url, url_start, url_end - url_start);
        url[url_end - url_start] = '\0';

        if (strncmp(url, "http://", 7) == 0)
        {
            strcpy(hostname, url + 7);
        }
        else
        {
            printf("Invalid HTTP request\n");
            continue;
        }

        printf("Connecting to server %s...\n", hostname);

        struct hostent *server = gethostbyname(hostname);

        if (server == NULL)
        {
            printf("ERROR, no such host as %s\n", hostname);
            continue;
        }

        int server_sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (server_sockfd < 0)
        {
            printf("ERROR opening socket to server\n");
            continue;
        }

        struct sockaddr_in server_addr;
        bzero((char *) &server_addr, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
        server_addr.sin_port = htons(80);

        if (connect(server_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        {
            printf("ERROR connecting to server %s\n", hostname);
            continue;
        }

        sprintf(response, "HTTP/1.1 200 OK\r\n\r\n");

        if (write(server_sockfd, buffer, strlen(buffer)) < 0)
        {
            printf("ERROR writing to server %s\n", hostname);
            continue;
        }

        printf("Request sent to server %s:\n%s\n\n", hostname, buffer);

        while (1)
        {
            bzero(buffer, BUFFER_SIZE);

            n = read(server_sockfd, buffer, BUFFER_SIZE);

            if (n < 0)
            {
                printf("ERROR reading from server %s\n", hostname);
                break;
            }

            if (n == 0)
            {
                printf("End of server response\n");
                break;
            }

            if (write(new_sockfd, buffer, n) < 0)
            {
                printf("ERROR writing to client\n");
                break;
            }
        }
        printf("Closing connection from client %s:%d\n\n",inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        close(new_sockfd);
        close(server_sockfd);
    }
    close(sockfd);
    return 0;
}