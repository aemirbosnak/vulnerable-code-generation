//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 80
#define MAX_BUFFER 1024

int main(int argc, char *argv[])
{
    int sockfd, response_length, bytes_received;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[MAX_BUFFER];
    char request[MAX_BUFFER];

    if (argc < 2)
    {
        printf("Usage: %s <website.com>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        perror("Error opening socket");
        return 1;
    }

    server = gethostbyname(argv[1]);

    if (server == NULL)
    {
        perror("Error resolving hostname");
        return 1;
    }

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr_list[0], (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Error connecting to server");
        return 1;
    }

    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    response_length = strlen(request);

    if (send(sockfd, request, response_length, 0) < 0)
    {
        perror("Error sending request");
        return 1;
    }

    printf("Request sent:\n%s\n", request);

    while ((bytes_received = recv(sockfd, buffer, MAX_BUFFER - 1, 0)) > 0)
    {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}