//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>

#define SMTP_PORT 25

int main()
{
    // Get the hostname and port number of the SMTP server
    char hostname[256];
    int port;
    printf("Enter the hostname of the SMTP server: ");
    scanf("%s", hostname);
    printf("Enter the port number of the SMTP server: ");
    scanf("%d", &port);

    // Create a socket to connect to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        perror("gethostbyname");
        return 1;
    }
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return 1;
    }

    // Read the welcome message from the SMTP server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the HELO command to the SMTP server
    if (send(sockfd, "HELO test\r\n", 12, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the MAIL FROM command to the SMTP server
    if (send(sockfd, "MAIL FROM: <sender@example.com>\r\n", 32, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the RCPT TO command to the SMTP server
    if (send(sockfd, "RCPT TO: <recipient@example.com>\r\n", 34, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the DATA command to the SMTP server
    if (send(sockfd, "DATA\r\n", 6, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the email body to the SMTP server
    if (send(sockfd, "This is the email body.\r\n", 25, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Send the dot command to the SMTP server to indicate the end of the email body
    if (send(sockfd, ".\r\n", 3, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Send the QUIT command to the SMTP server
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1)
    {
        perror("send");
        return 1;
    }

    // Read the response from the SMTP server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return 1;
    }

    // Close the socket to the SMTP server
    close(sockfd);

    return 0;
}