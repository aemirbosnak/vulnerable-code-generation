//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        fprintf(stderr, "Error: Unable to resolve hostname %s\n", hostname);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Error: Unable to create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error: Unable to connect to server");
        exit(1);
    }

    // Send USER command
    char user_cmd[MAX_LINE];
    sprintf(user_cmd, "USER %s\r\n", "username");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) == -1)
    {
        perror("Error: Unable to send USER command");
        exit(1);
    }

    // Receive server response
    char response[MAX_LINE];
    if (recv(sockfd, response, MAX_LINE, 0) == -1)
    {
        perror("Error: Unable to receive server response");
        exit(1);
    }

    // Check if USER command succeeded
    if (strncmp(response, "+OK", 3) != 0)
    {
        fprintf(stderr, "Error: Invalid username\n");
        exit(1);
    }

    // Send PASS command
    char pass_cmd[MAX_LINE];
    sprintf(pass_cmd, "PASS %s\r\n", "password");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) == -1)
    {
        perror("Error: Unable to send PASS command");
        exit(1);
    }

    // Receive server response
    if (recv(sockfd, response, MAX_LINE, 0) == -1)
    {
        perror("Error: Unable to receive server response");
        exit(1);
    }

    // Check if PASS command succeeded
    if (strncmp(response, "+OK", 3) != 0)
    {
        fprintf(stderr, "Error: Invalid password\n");
        exit(1);
    }

    // Send LIST command
    char list_cmd[MAX_LINE];
    sprintf(list_cmd, "LIST\r\n");
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1)
    {
        perror("Error: Unable to send LIST command");
        exit(1);
    }

    // Receive server response
    printf("Mailbox contents:\n");
    while (1)
    {
        if (recv(sockfd, response, MAX_LINE, 0) == -1)
        {
            perror("Error: Unable to receive server response");
            exit(1);
        }

        if (strncmp(response, ".", 1) == 0)
        {
            break;
        }

        printf("%s", response);
    }

    // Send QUIT command
    char quit_cmd[MAX_LINE];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) == -1)
    {
        perror("Error: Unable to send QUIT command");
        exit(1);
    }

    // Receive server response
    if (recv(sockfd, response, MAX_LINE, 0) == -1)
    {
        perror("Error: Unable to receive server response");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}