//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_ADDRESS "imap.gmail.com"
#define SERVER_PORT 993

int main()
{
    // Creating a socket for TCP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return -1;
    }

    // Resolving the server address and port number
    struct hostent* server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL)
    {
        printf("Error resolving host\n");
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr*) server->h_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    // Establishing a TCP connection with the server
    if (connect(sockfd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        return -1;
    }

    // Reading the server greeting message
    char greeting[1024];
    if (recv(sockfd, greeting, 1024, 0) == -1)
    {
        printf("Error receiving greeting message\n");
        return -1;
    }

    // Sending the login request
    char user[1024];
    char password[1024];
    printf("Enter your email address: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", password);

    char login_command[2048];
    sprintf(login_command, "LOGIN %s %s\r\n", user, password);

    if (send(sockfd, login_command, strlen(login_command), 0) == -1)
    {
        printf("Error sending login request\n");
        return -1;
    }

    // Reading the server response to the login request
    char login_response[1024];
    if (recv(sockfd, login_response, 1024, 0) == -1)
    {
        printf("Error receiving login response\n");
        return -1;
    }

    // Selecting the inbox folder
    if (send(sockfd, "SELECT INBOX\r\n", 14, 0) == -1)
    {
        printf("Error sending SELECT command\n");
        return -1;
    }

    // Reading the server response to the SELECT command
    char select_response[1024];
    if (recv(sockfd, select_response, 1024, 0) == -1)
    {
        printf("Error receiving SELECT response\n");
        return -1;
    }

    // Fetching the list of messages in the inbox
    if (send(sockfd, "FETCH 1:* FULL\r\n", 17, 0) == -1)
    {
        printf("Error sending FETCH command\n");
        return -1;
    }

    // Reading the server response to the FETCH command
    char fetch_response[1024];
    if (recv(sockfd, fetch_response, 1024, 0) == -1)
    {
        printf("Error receiving FETCH response\n");
        return -1;
    }

    // Displaying the list of messages
    printf("%s", fetch_response);

    // Closing the TCP connection
    if (close(sockfd) == -1)
    {
        printf("Error closing socket\n");
        return -1;
    }

    return 0;
}