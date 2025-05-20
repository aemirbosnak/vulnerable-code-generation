//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main()
{
    int sockfd, port, nbytes, i, j, start, end, time_start, time_end;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_port = htons(8080);
    server_addr.sin_family = AF_INET;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start the timer
    time_start = time(NULL);

    // Send a message to the server
    printf("Enter the message you want to send: ");
    scanf("%s", buffer);
    nbytes = send(sockfd, buffer, BUFFER_SIZE, 0);

    // Receive a message from the server
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);

    // End the timer
    time_end = time(NULL);

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Calculate the time taken
    int time_taken = time_end - time_start;

    // Print the time taken
    printf("Time taken: %d seconds\n", time_taken);

    // Close the socket
    close(sockfd);

    return 0;
}