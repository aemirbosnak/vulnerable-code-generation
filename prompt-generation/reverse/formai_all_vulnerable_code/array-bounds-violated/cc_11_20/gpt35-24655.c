//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LENGTH 500

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_LENGTH];

    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error: no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
    {
        perror("Error connecting");
        exit(1);
    }

    printf("Connected to server\n");

    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    printf("Enter your email address: ");
    bzero(buffer, MAX_LENGTH);
    fgets(buffer, MAX_LENGTH-1, stdin);
    n = strlen(buffer);
    if (buffer[n-1] == '\n')
    {
        buffer[n-1] = '\0';
    }

    sprintf(buffer, "HELO %s\r\n", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    bzero(buffer, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    printf("Enter recipient email address: ");
    bzero(buffer, MAX_LENGTH);
    fgets(buffer, MAX_LENGTH-1, stdin);
    n = strlen(buffer);
    if (buffer[n-1] == '\n')
    {
        buffer[n-1] = '\0';
    }

    sprintf(buffer, "MAIL FROM:<%s>\r\n", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    bzero(buffer, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    printf("Enter email subject: ");
    bzero(buffer, MAX_LENGTH);
    fgets(buffer, MAX_LENGTH-1, stdin);
    n = strlen(buffer);
    if (buffer[n-1] == '\n')
    {
        buffer[n-1] = '\0';
    }

    sprintf(buffer, "DATA\r\nSubject: %s\r\n", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    bzero(buffer, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    printf("Enter email body: ");
    bzero(buffer, MAX_LENGTH);
    fgets(buffer, MAX_LENGTH-1, stdin);
    n = strlen(buffer);
    if (buffer[n-1] == '\n')
    {
        buffer[n-1] = '\0';
    }

    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    sprintf(buffer, "\r\n.\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    bzero(buffer, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0)
    {
        perror("Error sending");
        exit(1);
    }

    bzero(buffer, MAX_LENGTH);
    n = recv(sockfd, buffer, MAX_LENGTH, 0);
    buffer[n] = '\0';
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}