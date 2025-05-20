//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_ADDR "smtp.server.com"
#define SERVER_PORT 25

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error: Could not create socket\n");
        exit(-1);
    }

    server = gethostbyname(SERVER_ADDR);

    if (server == NULL)
    {
        printf("Error: Could not find server\n");
        exit(-1);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;

    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error: Could not connect to server\n");
        exit(-1);
    }

    printf("Connected to server\n");

    // Send HELO command to server
    n = write(sockfd, "HELO myclient.com\r\n", strlen("HELO myclient.com\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    // Send MAIL FROM command to server
    n = write(sockfd, "MAIL FROM:<sender@myclient.com>\r\n", strlen("MAIL FROM:<sender@myclient.com>\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    // Send RCPT TO command to server
    n = write(sockfd, "RCPT TO:<recipient@server.com>\r\n", strlen("RCPT TO:<recipient@server.com>\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    // Send DATA command to server
    n = write(sockfd, "DATA\r\n", strlen("DATA\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    // Send message body to server
    n = write(sockfd, "Subject: Test message\r\n\r\nThis is a test message.\r\n.\r\n", strlen("Subject: Test message\r\n\r\nThis is a test message.\r\n.\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    // Send QUIT command to server
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));

    if (n < 0)
    {
        printf("Error: Could not write to socket\n");
        exit(-1);
    }

    bzero(buffer, 256);

    n = read(sockfd, buffer, 255);

    if (n < 0)
    {
        printf("Error: Could not read from socket\n");
        exit(-1);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}