//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_SIZE 4096

int main()
{
    int sockfd, n, i;
    char sendline[MAX_SIZE + 1], recvline[MAX_SIZE + 1];
    struct sockaddr_in servaddr;

    // Creating Socket File Descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Initializing server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(993);
    inet_pton(AF_INET, "imap.gmail.com", &servaddr.sin_addr);

    // Connecting to the IMAP server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Error: Could not connect to server\n");
        exit(1);
    }

    // Receive server greeting
    n = recv(sockfd, recvline, MAX_SIZE, 0);

    if (n < 0)
    {
        printf("Error: Could not receive server greeting\n");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    // Send login command
    sprintf(sendline, "%s\r\n", "LOGIN user@gmail.com password");
    n = send(sockfd, sendline, strlen(sendline), 0);

    if (n < 0)
    {
        printf("Error: Could not send login command\n");
        exit(1);
    }

    // Receive login response
    n = recv(sockfd, recvline, MAX_SIZE, 0);

    if (n < 0)
    {
        printf("Error: Could not receive login response\n");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    // Send select command
    sprintf(sendline, "%s\r\n", "SELECT Inbox");
    n = send(sockfd, sendline, strlen(sendline), 0);

    if (n < 0)
    {
        printf("Error: Could not send select command\n");
        exit(1);
    }

    // Receive select response
    n = recv(sockfd, recvline, MAX_SIZE, 0);

    if (n < 0)
    {
        printf("Error: Could not receive select response\n");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    // Send list command
    sprintf(sendline, "%s\r\n", "LIST");
    n = send(sockfd, sendline, strlen(sendline), 0);

    if (n < 0)
    {
        printf("Error: Could not send list command\n");
        exit(1);
    }

    // Receive list response
    n = recv(sockfd, recvline, MAX_SIZE, 0);

    if (n < 0)
    {
        printf("Error: Could not receive list response\n");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    // Send logout command
    sprintf(sendline, "%s\r\n", "LOGOUT");
    n = send(sockfd, sendline, strlen(sendline), 0);

    if (n < 0)
    {
        printf("Error: Could not send logout command\n");
        exit(1);
    }

    // Receive logout response
    n = recv(sockfd, recvline, MAX_SIZE, 0);

    if (n < 0)
    {
        printf("Error: Could not receive logout response\n");
        exit(1);
    }

    recvline[n] = '\0';
    printf("%s\n", recvline);

    // Closing connection
    close(sockfd);

    return 0;
}