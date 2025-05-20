//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    struct sockaddr_in server_addr;
    int sockfd, bytes_sent, bytes_received, i, t, start_time, end_time;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send a message to the server
    printf("Enter a message: ");
    scanf("%s", buffer);
    bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_sent < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message from the server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    t = end_time - start_time;

    // Print the message received from the server
    printf("Message received: %s\n", buffer);

    // Print the time taken
    printf("Time taken: %d seconds\n", t);

    // Close the socket
    close(sockfd);

    return 0;
}