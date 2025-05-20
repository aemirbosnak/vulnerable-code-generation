//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];

    if (argc != 3)
    {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
    {
        perror("Error converting IP address");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Send HELO command
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", "example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending HELO command");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending MAIL FROM command");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", "recipient@example.com");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending RCPT TO command");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending DATA command");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send email body
    snprintf(buffer, sizeof(buffer), "Subject: Test email\r\n\r\nThis is a test email.\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending email body");
        return EXIT_FAILURE;
    }

    // Send dot to terminate email body
    snprintf(buffer, sizeof(buffer), ".\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending dot to terminate email body");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Send QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending QUIT command");
        return EXIT_FAILURE;
    }

    // Receive server response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("Error receiving server response");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    close(sockfd);
    return EXIT_SUCCESS;
}