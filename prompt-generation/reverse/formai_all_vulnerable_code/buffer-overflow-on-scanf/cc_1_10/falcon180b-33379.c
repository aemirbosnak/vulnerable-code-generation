//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define SERVER "127.0.0.1"
#define PORT 110

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50];
    char password[50];
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        return 1;
    }

    // Authenticate with username and password
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        return 1;
    }
    printf("Server response: %s", buffer);

    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        return 1;
    }
    printf("Server response: %s", buffer);

    // Retrieve number of messages
    sprintf(buffer, "STAT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        return 1;
    }
    printf("Server response: %s", buffer);

    // Retrieve message headers
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        return 1;
    }
    printf("Server response: %s", buffer);

    // Retrieve message body
    int message_number = atoi(buffer) - 1;
    sprintf(buffer, "RETR %d\r\n", message_number);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n <= 0)
    {
        printf("Error receiving from server\n");
        return 1;
    }
    printf("Server response: %s", buffer);

    char *message_body = &buffer[4];
    printf("Message body: %s", message_body);

    // Close socket
    close(sockfd);

    return 0;
}