//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// Recursive function to read and print messages from server
void readMessage(int sockfd, struct sockaddr_in servaddr)
{
    char buffer[1024];
    socklen_t len = sizeof(servaddr);

    // Receive message from server
    ssize_t n = recvfrom(sockfd, (char *)buffer, 1024, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);

    // If the message is not empty, print it
    if (n > 0)
    {
        buffer[n] = '\0';
        printf("Server : %s\n", buffer);
    }

    // Call recursively to read more messages
    readMessage(sockfd, servaddr);
}

int main()
{
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket creation failed!\n");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("Connection failed!\n");
        exit(EXIT_FAILURE);
    }

    // Create child process to read messages from server
    if (fork() == 0)
    {
        readMessage(sockfd, servaddr);
    }

    // Parent process sends messages to server
    while (1)
    {
        printf("Enter message : ");
        fgets(buffer, 1024, stdin);

        // Check for 'quit' command to exit from loop
        if (strcmp(buffer, "quit\n") == 0)
            break;

        // Send message to server
        sendto(sockfd, (const char *)buffer, strlen(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    }

    // Close socket
    close(sockfd);

    return 0;
}