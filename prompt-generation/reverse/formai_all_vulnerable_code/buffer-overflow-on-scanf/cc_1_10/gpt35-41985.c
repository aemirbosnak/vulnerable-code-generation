//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: synchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, recv_len;
    struct sockaddr_in server_addr;
    char username[50], password[50], mailbox[50], buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE], response[BUFFER_SIZE], mailbox_name[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if(sockfd < 0)
    {
        printf("\nError in socket creation");
        exit(1);
    }

    printf("\nEnter server address: ");
    scanf("%s", buffer);
    server_addr.sin_addr.s_addr = inet_addr(buffer);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("\nError in connection");
        exit(1);
    }

    // Receive server greeting
    memset(response, '\0', BUFFER_SIZE);
    recv_len = recv(sockfd, response, sizeof(response), 0);
    printf("\nServer: %s", response);

    // Send login username
    printf("\nEnter username: ");
    scanf("%s", username);
    sprintf(command, "1 LOGIN %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    // Receive login response
    memset(response, '\0', BUFFER_SIZE);
    recv_len = recv(sockfd, response, sizeof(response), 0);
    printf("\nServer: %s", response);

    // Send login password
    printf("\nEnter password: ");
    scanf("%s", password);
    sprintf(command, "1 LOGIN %s %s\r\n", username, password);
    send(sockfd, command, strlen(command), 0);

    // Receive login response
    memset(response, '\0', BUFFER_SIZE);
    recv_len = recv(sockfd, response, sizeof(response), 0);
    printf("\nServer: %s", response);

    // Select mailbox
    printf("\nEnter mailbox to select: ");
    scanf("%s", mailbox_name);
    sprintf(command, "1 SELECT %s\r\n", mailbox_name);
    send(sockfd, command, strlen(command), 0);

    // Receive mailbox response
    memset(response, '\0', BUFFER_SIZE);
    recv_len = recv(sockfd, response, sizeof(response), 0);
    printf("\nServer: %s", response);

    // Logout and close connection
    sprintf(command, "1 LOGOUT\r\n");
    send(sockfd, command, strlen(command), 0);
    close(sockfd);

    printf("\nConnection closed");
    return 0;
}