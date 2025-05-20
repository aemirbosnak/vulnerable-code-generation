//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SMTP_PORT 25

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in server;
    char buffer[1024];

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server> <message>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        exit(1);
    }

    // Get the server's IP address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        fprintf(stderr, "Unknown server '%s'\n", argv[1]);
        exit(1);
    }

    // Set up the server's address
    server.sin_family = AF_INET;
    server.sin_port = htons(SMTP_PORT);
    server.sin_addr = *(struct in_addr *) host->h_addr;

    // Connect to the server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0)
    {
        perror("connect");
        exit(1);
    }

    // Send the HELO command
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the MAIL FROM command
    sprintf(buffer, "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the RCPT TO command
    sprintf(buffer, "RCPT TO: <%s>\r\n", "recipient@example.com");
    if (send(sock, buffer, strlen(buffer), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the DATA command
    if (send(sock, "DATA\r\n", strlen("DATA\r\n"), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the message
    if (send(sock, argv[2], strlen(argv[2]), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Send the end of the message
    if (send(sock, "\r\n.\r\n", strlen("\r\n.\r\n"), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Send the QUIT command
    if (send(sock, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sock);

    return 0;
}