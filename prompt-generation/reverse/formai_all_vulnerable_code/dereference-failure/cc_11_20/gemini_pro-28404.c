//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int sockfd, port;
    struct sockaddr_in serv_addr;
    char *host, *msg, buf[1024];

    printf("Enter the IP address of the SMTP server: ");
    scanf("%s", host);

    printf("Enter the port number: ");
    scanf("%d", &port);

    printf("Enter the message: ");
    scanf("%s", msg);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket creation failed");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to the SMTP server.\n");

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", host);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", buf);

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", buf);

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", "recipient@example.com");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", buf);

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", buf);

    // Send the message
    if (send(sockfd, msg, strlen(msg), 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Send the dot to indicate the end of the message
    if (send(sockfd, ".\r\n", 3, 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the SMTP server
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        perror("recv failed");
        exit(1);
    }

    printf("Received: %s\n", buf);

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) < 0)
    {
        perror("send failed");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}