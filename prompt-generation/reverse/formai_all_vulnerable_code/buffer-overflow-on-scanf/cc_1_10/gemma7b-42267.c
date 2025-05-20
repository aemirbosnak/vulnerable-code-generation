//Gemma-7B DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <netdb.h>

#define SERVER_PORT 5000
#define MAX_BUFFER_SIZE 1024

int main()
{
    // Define socket and client structures
    int sockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Define server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_aton("127.0.0.1", (struct in_addr *)&server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive messages
    char buffer[MAX_BUFFER_SIZE];
    int bytes_sent, bytes_received;

    // Loop until client disconnects
    while (1)
    {
        // Get message from client
        bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received < 0)
        {
            perror("Error receiving message");
            exit(1);
        }

        // Print message from client
        printf("Client: %s\n", buffer);

        // Send message to client
        printf("Enter your message: ");
        scanf("%s", buffer);

        // Send message to client
        bytes_sent = send(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_sent < 0)
        {
            perror("Error sending message");
            exit(1);
        }

        // Check if client has disconnected
        if (bytes_received == 0)
        {
            break;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}