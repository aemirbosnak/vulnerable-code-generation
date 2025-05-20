//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Usage: %s <server-ip> <server-port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_BUFFER] = {0};

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // SMTP Client handshake with server
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    char helo[50] = {"HELO\r\n"};
    if (send(sockfd, helo, strlen(helo), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    // Sending email using SMTP
    char mail_from[50] = {"MAIL FROM: <youremail@domain.com>\r\n"};
    if (send(sockfd, mail_from, strlen(mail_from), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    char rcpt_to[50] = {"RCPT TO: <recipientemail@domain.com>\r\n"};
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    char data[50] = {"DATA\r\n"};
    if (send(sockfd, data, strlen(data), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    char message[500] = {"From: <youremail@domain.com>\r\nTo: <recipientemail@domain.com>\r\nSubject: SMTP Client Example\r\n\r\nThis is a test email sent using SMTP Client example program in C language. Hope this email finds you well.\r\n.\r\n"};
    if (send(sockfd, message, strlen(message), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    char quit[50] = {"QUIT\r\n"};
    if (send(sockfd, quit, strlen(quit), 0) < 0)
    {
        perror("send failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0)
    {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s\n", buffer);

    close(sockfd);

    return 0;
}