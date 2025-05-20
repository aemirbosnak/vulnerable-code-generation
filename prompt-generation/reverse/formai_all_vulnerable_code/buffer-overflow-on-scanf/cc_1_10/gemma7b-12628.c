//Gemma-7B DATASET v1.0 Category: Email Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 5000

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_port = htons(SERVER_PORT);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send and receive messages
    char message[1024];
    while (1)
    {
        // Get the message from the user
        printf("Enter your message: ");
        scanf("%s", message);

        // Send the message to the server
        send(sockfd, message, strlen(message) + 1, 0);

        // Receive the message from the server
        recv(sockfd, message, 1024, 0);

        // Print the message from the server
        printf("Server: %s\n", message);

        // Check if the user wants to quit
        printf("Enter 'q' to quit: ");
        char quit;
        scanf("%c", &quit);

        if (quit == 'q')
        {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}