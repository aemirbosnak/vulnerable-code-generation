//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define SERVER "imap.gmail.com"
#define USER "youremail@gmail.com"
#define PASSWORD "yourpassword"

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 993; // IMAP port number

    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a socket
    if (sockfd < 0) 
    {
        fprintf(stderr, "Error: Cannot open socket.\n");
        exit(1);
    }

    server = gethostbyname(SERVER); // Get the server address from DNS
    if (server == NULL) 
    {
        fprintf(stderr,"Error: Cannot find host.\n");
        exit(1);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr)); // Initialize the server address
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
    {
        fprintf(stderr, "Error: Cannot connect to server.\n");
        exit(1);
    }

    // Receive the server's greeting message
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot receive message from server.\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the login command
    sprintf(buffer, "login %s %s\r\n", USER, PASSWORD);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot send message to server.\n");
        exit(1);
    }

    // Receive the login response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot receive message from server.\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the select command
    sprintf(buffer, "select inbox\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot send message to server.\n");
        exit(1);
    }

    // Receive the select response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot receive message from server.\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the fetch command
    sprintf(buffer, "fetch 1 body\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot send message to server.\n");
        exit(1);
    }

    // Receive the fetch response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot receive message from server.\n");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the logout command
    sprintf(buffer, "logout\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
    {
        fprintf(stderr, "Error: Cannot send message to server.\n");
        exit(1);
    }

    // Receive the logout response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0) 
    {
        fprintf(stderr, "Error: Cannot receive message from server.\n");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd); // Close the socket

    return 0;
}