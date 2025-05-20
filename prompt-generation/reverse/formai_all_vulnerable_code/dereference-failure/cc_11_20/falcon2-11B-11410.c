//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    char username[MAX_SIZE], password[MAX_SIZE], message[MAX_SIZE];

    if (argc!= 4)
    {
        fprintf(stderr, "Usage: %s username password message\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[1]);
    strcpy(password, argv[2]);
    strcpy(message, argv[3]);

    // Connect to SMTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(1);
    }

    server = gethostbyname("smtp.example.com");
    if (server == NULL)
    {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    fprintf(stderr, "Connected to %s on port %d\n", server->h_name, ntohs(serv_addr.sin_port));

    // Send HELO command
    strcpy(buffer, "HELO Client\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send AUTH command
    strcpy(buffer, "AUTH LOGIN\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send username and password
    strcpy(buffer, "Username: ");
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    strcpy(buffer, "Password: ");
    strcat(buffer, password);
    strcat(buffer, "\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send MAIL FROM command
    strcpy(buffer, "MAIL FROM:<");
    strcat(buffer, username);
    strcat(buffer, ">\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send RCPT TO command
    strcpy(buffer, "RCPT TO:<");
    strcat(buffer, username);
    strcat(buffer, ">\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send DATA command
    strcpy(buffer, "DATA\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send email message
    strcpy(buffer, "Subject: Test Email\r\n");
    strcat(buffer, "To: ");
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    strcat(buffer, "From: ");
    strcat(buffer, username);
    strcat(buffer, "\r\n");
    strcat(buffer, "\r\n");
    strcat(buffer, message);
    strcat(buffer, "\r\n.\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    // Send QUIT command
    strcpy(buffer, "QUIT\r\n");
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        perror("write");
        exit(1);
    }

    close(sockfd);

    return 0;
}