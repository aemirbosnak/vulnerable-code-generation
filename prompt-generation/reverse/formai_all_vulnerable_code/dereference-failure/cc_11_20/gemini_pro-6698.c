//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <SMTP server> <sender email> <recipient email>\n", argv[0]);
        return 1;
    }

    // Get the SMTP server's IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Could not resolve SMTP server hostname\n");
        return 1;
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Create a socket to connect to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Could not create socket\n");
        return 1;
    }

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Could not connect to SMTP server\n");
        return 1;
    }

    // Read the SMTP server's welcome message
    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's welcome message\n");
        return 1;
    }

    // Send the HELO command
    sprintf(buf, "HELO %s\r\n", argv[1]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send HELO command\n");
        return 1;
    }

    // Read the SMTP server's response to the HELO command
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's response to the HELO command\n");
        return 1;
    }

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send MAIL FROM command\n");
        return 1;
    }

    // Read the SMTP server's response to the MAIL FROM command
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's response to the MAIL FROM command\n");
        return 1;
    }

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send RCPT TO command\n");
        return 1;
    }

    // Read the SMTP server's response to the RCPT TO command
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's response to the RCPT TO command\n");
        return 1;
    }

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send DATA command\n");
        return 1;
    }

    // Read the SMTP server's response to the DATA command
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's response to the DATA command\n");
        return 1;
    }

    // Send the email body
    sprintf(buf, "Subject: Test email\r\n\r\nThis is a test email.\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send email body\n");
        return 1;
    }

    // Send the dot to indicate the end of the email body
    sprintf(buf, ".\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send dot to indicate the end of the email body\n");
        return 1;
    }

    // Read the SMTP server's response to the dot
    if (recv(sockfd, buf, sizeof(buf), 0) < 0)
    {
        printf("Could not receive SMTP server's response to the dot\n");
        return 1;
    }

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0)
    {
        printf("Could not send QUIT command\n");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}