//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAXBUFFER 1024

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("Error creating socket\n");
        return -1;
    }

    server = gethostbyname(argv[1]);

    if(server == NULL)
    {
        printf("Error getting host by name\n");
        return -1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting to server\n");
        return -1;
    }

    char buffer[MAXBUFFER];
    memset(&buffer, 0, sizeof(buffer));

    int n = read(sockfd, buffer, MAXBUFFER-1);

    if(n < 0)
    {
        printf("Error reading from socket\n");
        return -1;
    }

    printf("Server: %s\n", buffer);

    char username[MAXBUFFER], password[MAXBUFFER];

    printf("Enter username: ");
    scanf("%s", username);

    sprintf(buffer, "USER %s\r\n", username);
    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0)
    {
        printf("Error writing to socket\n");
        return -1;
    }

    memset(&buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, MAXBUFFER-1);

    if(n < 0)
    {
        printf("Error reading from socket\n");
        return -1;
    }

    printf("Server: %s\n", buffer);

    printf("Enter password: ");
    scanf("%s", password);

    sprintf(buffer, "PASS %s\r\n", password);
    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0)
    {
        printf("Error writing to socket\n");
        return -1;
    }

    memset(&buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, MAXBUFFER-1);

    if(n < 0)
    {
        printf("Error reading from socket\n");
        return -1;
    }

    printf("Server: %s\n", buffer);

    sprintf(buffer, "STAT\r\n");
    n = write(sockfd, buffer, strlen(buffer));

    if(n < 0)
    {
        printf("Error writing to socket\n");
        return -1;
    }

    memset(&buffer, 0, sizeof(buffer));

    n = read(sockfd, buffer, MAXBUFFER-1);

    if(n < 0)
    {
        printf("Error reading from socket\n");
        return -1;
    }

    printf("Server: %s\n", buffer);

    close(sockfd);
    return 0;
}