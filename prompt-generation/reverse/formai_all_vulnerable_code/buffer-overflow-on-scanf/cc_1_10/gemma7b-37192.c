//Gemma-7B DATASET v1.0 Category: Building a POP3 Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define SERVER_PORT 143

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive messages
    char msg[1024];
    while (1)
    {
        // Get the message from the user
        printf("Enter a message: ");
        fgets(msg, 1024, stdin);

        // Send the message to the server
        if (send(sockfd, msg, strlen(msg) + 1, 0) < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        // Receive the message from the server
        int len = recv(sockfd, msg, 1024, 0);

        // If the message is not empty, print it to the console
        if (len > 0)
        {
            printf("Received: %s\n", msg);
        }

        // Check if the user wants to quit
        printf("Enter 'q' to quit: ");
        char quit[10];
        scanf("%s", quit);

        // If the user wants to quit, exit the program
        if (strcmp(quit, "q") == 0)
        {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}