//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define BACKLOG 10
#define MAX_REQUEST_SIZE 2048
#define MAX_RESPONSE_SIZE 8192

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int connect_to_server(char *hostname, int port)
{
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char ip[INET_ADDRSTRLEN];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(hostname);
    if(server == NULL)
        error("ERROR, no such host");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    inet_ntop(AF_INET, &(serv_addr.sin_addr), ip, INET_ADDRSTRLEN);

    printf("Connecting to server %s:%d...\n", ip, port);

    if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0 )
        error("ERROR connecting to server");

    printf("Connected to server %s:%d\n", ip, port);

    return sockfd;
}

void proxy(int client_fd, char *method, char *path, char *http_version, char *buffer)
{
    int server_fd;
    int n;
    char response[MAX_RESPONSE_SIZE];
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    printf("%s %s %s\n", method, path, http_version);

    server_fd = connect_to_server("www.google.com", 80);

    n = send(server_fd, buffer, strlen(buffer), 0);
    if(n < 0)
        error("ERROR writing to socket");

    setsockopt(server_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv));

    n = recv(server_fd, response, MAX_RESPONSE_SIZE - 1, 0);
    if(n < 0)
        error("ERROR reading from socket");

    response[n] = '\0';

    printf("%s\n", response);

    n = send(client_fd, response, strlen(response), 0);
    if(n < 0)
        error("ERROR writing to socket");

    close(server_fd);
}

int main(int argc, char* argv[])
{
    int sockfd, newsockfd;
    int yes = 1;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char request_buffer[MAX_REQUEST_SIZE];
    char *method, *path, *http_version;
    int n;

    if(argc != 2)
    {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
        error("ERROR opening socket");

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1])) ;

    if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, BACKLOG);

    while(1)
    {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if(newsockfd < 0)
            error("ERROR on accept");

        memset(request_buffer, 0, MAX_REQUEST_SIZE);

        n = recv(newsockfd, request_buffer, MAX_REQUEST_SIZE - 1, 0);
        if(n < 0)
            error("ERROR reading from socket");

        method = strtok(request_buffer, " ");
        path = strtok(NULL, " ");
        http_version = strtok(NULL, "\r\n");

        proxy(newsockfd, method, path, http_version, request_buffer);

        close(newsockfd);
    }

    return 0;
}