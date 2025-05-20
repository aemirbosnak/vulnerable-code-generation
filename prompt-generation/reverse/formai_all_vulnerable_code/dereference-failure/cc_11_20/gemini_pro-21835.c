//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

int main(int argc, char **argv)
{
    // Check if the user entered a URL
    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return 1;
    }

    // Parse the URL
    char *host = NULL;
    char *path = NULL;
    int port = 80;
    char *scheme = "http";
    if (strncmp(argv[1], "http://", 7) == 0)
    {
        scheme = "http";
        host = argv[1] + 7;
    }
    else if (strncmp(argv[1], "https://", 8) == 0)
    {
        scheme = "https";
        host = argv[1] + 8;
    }
    else
    {
        host = argv[1];
    }

    // Parse the host and port
    char *colon = strchr(host, ':');
    if (colon != NULL)
    {
        *colon = '\0';
        port = atoi(colon + 1);
    }

    // Parse the path
    char *slash = strchr(host, '/');
    if (slash != NULL)
    {
        path = slash;
    }
    else
    {
        path = "/";
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0)
    {
        perror("inet_pton");
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
    {
        perror("connect");
        return 1;
    }

    // Send the HTTP request
    char request[MAX_LINE];
    sprintf(request, "GET %s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", path, scheme, host);
    if (send(sockfd, request, strlen(request), 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Receive the HTTP response
    char response[MAX_LINE];
    int n = 0;
    while ((n = recv(sockfd, response, MAX_LINE, 0)) > 0)
    {
        fwrite(response, 1, n, stdout);
    }
    if (n == -1)
    {
        perror("recv");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}