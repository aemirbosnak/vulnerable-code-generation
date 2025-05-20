//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define IMAP_PORT 143

int main(int argc, char *argv[])
{
    // Check if the correct number of arguments are provided
    if (argc < 3)
    {
        fprintf(stderr, "Usage: %s <server_address> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the server address, username, and password from the command line arguments
    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create a socket for communicating with the IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Resolve the server address
    struct hostent *host = gethostbyname(server_address);
    if (host == NULL)
    {
        perror("Error resolving server address");
        return EXIT_FAILURE;
    }

    // Connect to the IMAP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr_list[0];
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Send the login command
    char login_command[1024];
    snprintf(login_command, sizeof(login_command), "LOGIN %s %s\r\n", username, password);
    if (send(sockfd, login_command, strlen(login_command), 0) == -1)
    {
        perror("Error sending login command");
        return EXIT_FAILURE;
    }

    // Receive the login response
    char login_response[1024];
    if (recv(sockfd, login_response, sizeof(login_response), 0) == -1)
    {
        perror("Error receiving login response");
        return EXIT_FAILURE;
    }

    // Check if the login was successful
    if (strncmp(login_response, "+OK", 3) != 0)
    {
        fprintf(stderr, "Error: %s", login_response);
        return EXIT_FAILURE;
    }

    // Send the list command
    char list_command[1024];
    snprintf(list_command, sizeof(list_command), "LIST \"\" *\r\n");
    if (send(sockfd, list_command, strlen(list_command), 0) == -1)
    {
        perror("Error sending list command");
        return EXIT_FAILURE;
    }

    // Receive the list response
    char list_response[1024];
    if (recv(sockfd, list_response, sizeof(list_response), 0) == -1)
    {
        perror("Error receiving list response");
        return EXIT_FAILURE;
    }

    // Parse the list response and print the mailbox names
    char *mailbox_name;
    char *end = list_response;
    while ((mailbox_name = strtok(end, "\r\n")) != NULL)
    {
        printf("%s\n", mailbox_name);
        end = NULL;
    }

    // Send the logout command
    char logout_command[1024];
    snprintf(logout_command, sizeof(logout_command), "LOGOUT\r\n");
    if (send(sockfd, logout_command, strlen(logout_command), 0) == -1)
    {
        perror("Error sending logout command");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}