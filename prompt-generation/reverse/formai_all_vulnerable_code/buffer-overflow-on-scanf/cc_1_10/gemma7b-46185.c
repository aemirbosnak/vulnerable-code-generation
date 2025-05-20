//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, i, bufsize, client_fd;
    char hostname[256], buf[MAX_BUFFER_SIZE], message[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Get the hostname and port from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number: ");
    scanf("%d", &port);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to the server");
        exit(1);
    }

    // Send a message to the server
    printf("Enter your message: ");
    scanf("%s", message);

    n = send(sockfd, message, MAX_BUFFER_SIZE, 0);

    // Receive a message from the server
    n = recv(sockfd, buf, MAX_BUFFER_SIZE, 0);

    // Print the server's message
    printf("Server's message: %s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}