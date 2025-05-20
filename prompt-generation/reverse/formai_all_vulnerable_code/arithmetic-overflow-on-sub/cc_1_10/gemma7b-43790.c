//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sockfd, n, bytes_sent, bytes_received, start_time, end_time;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server's address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
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

    // Receive a message from the server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the results
    printf("Message received: %s\n", buffer);
    printf("Time taken: %d seconds\n", time_taken);

    // Close the socket
    close(sockfd);

    return 0;
}