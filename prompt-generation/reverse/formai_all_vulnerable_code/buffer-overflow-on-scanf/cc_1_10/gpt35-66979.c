//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 21

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0)
    {
        perror("Error opening socket");
        exit(1);
    }

    // Initialize server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0)
    {
        perror("Invalid address");
        exit(1);
    }

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection failed");
        exit(1);
    }

    // Receive connection message
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send username
    memset(buffer, 0, sizeof(buffer));
    printf("Enter username: ");
    scanf("%s", buffer);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive username response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send password
    memset(buffer, 0, sizeof(buffer));
    printf("Enter password: ");
    scanf("%s", buffer);
    strcat(buffer, "\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive password response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send PWD command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "PWD\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Receive PWD response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Close connection
    close(sockfd);
    return 0;
}