//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>

#define PORT 8080
#define MAX_LINE 1024

int main()
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    // Set the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Send a message to the server
    strcpy(sendline, "Hello, world!");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive a message from the server
    if ((n = recv(sockfd, recvline, MAX_LINE, 0)) < 0) {
        perror("recv error");
        exit(1);
    }

    // Print the received message
    recvline[n] = '\0';
    printf("Received: %s\n", recvline);

    // Close the socket
    close(sockfd);

    return 0;
}