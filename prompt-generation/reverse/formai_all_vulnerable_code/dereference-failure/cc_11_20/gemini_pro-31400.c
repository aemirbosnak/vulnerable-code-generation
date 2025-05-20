//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char *argv[])
{
    // Check if the user has provided the server name
    if (argc < 2)
    {
        printf("Usage: %s <server_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the server name from the command line
    char *server_name = argv[1];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the server name to an IP address
    struct hostent *host = gethostbyname(server_name);
    if (host == NULL)
    {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create a socket address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the welcome message from the server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the welcome message
    printf("%s", buffer);

    // Send the USER command
    char user_cmd[1024];
    sprintf(user_cmd, "USER %s\r\n", "username");
    if (send(sockfd, user_cmd, strlen(user_cmd), 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the USER command
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the response to the USER command
    printf("%s", buffer);

    // Send the PASS command
    char pass_cmd[1024];
    sprintf(pass_cmd, "PASS %s\r\n", "password");
    if (send(sockfd, pass_cmd, strlen(pass_cmd), 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the PASS command
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the response to the PASS command
    printf("%s", buffer);

    // Send the LIST command
    char list_cmd[1024];
    sprintf(list_cmd, "LIST\r\n");
    if (send(sockfd, list_cmd, strlen(list_cmd), 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the LIST command
    while (1)
    {
        if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
        {
            perror("recv");
            exit(EXIT_FAILURE);
        }

        // Print the response to the LIST command
        printf("%s", buffer);

        // Check if the response is the end of the list
        if (strstr(buffer, ".") != NULL)
        {
            break;
        }
    }

    // Send the QUIT command
    char quit_cmd[1024];
    sprintf(quit_cmd, "QUIT\r\n");
    if (send(sockfd, quit_cmd, strlen(quit_cmd), 0) < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive the response to the QUIT command
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Print the response to the QUIT command
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}