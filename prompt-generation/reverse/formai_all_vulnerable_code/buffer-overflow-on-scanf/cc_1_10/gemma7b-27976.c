//Gemma-7B DATASET v1.0 Category: Interprocess communication ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define PORT 5000

int main()
{
    int sockfd, newsockfd, pid, client_len;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, &client_len);

    // Accept a client connection
    newsockfd = accept(sockfd, NULL, NULL);
    if (newsockfd < 0)
    {
        perror("Error accepting client connection");
        exit(1);
    }

    // Fork the client process
    pid = fork();
    if (pid < 0)
    {
        perror("Error forking client process");
        exit(1);
    }

    // Child process
    if (pid == 0)
    {
        // Receive data from the client
        recv(newsockfd, buffer, 1024, 0);
        printf("Received: %s", buffer);

        // Send data to the client
        printf("Enter your message: ");
        scanf("%s", buffer);
        send(newsockfd, buffer, strlen(buffer) + 1, 0);

        // Close the client connection
        close(newsockfd);

        // Exit the child process
        exit(0);
    }

    // Parent process
    wait(NULL);

    // Close the socket
    close(sockfd);

    return 0;
}