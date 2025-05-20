//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define HOST_NAME "192.168.1.1"
#define PORT 8080

int main()
{
    int sockfd, result, bytes_sent, bytes_received;
    struct sockaddr_in server_addr;
    char buffer[1024];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(HOST_NAME);
    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send a ping message
    sprintf(buffer, "Ping!");
    bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

    // Receive the pong message
    bytes_received = recv(sockfd, buffer, 1024, 0);

    // End the timer
    end_time = time(NULL);

    // Calculate the time taken
    int time_taken = end_time - start_time;

    // Print the results
    printf("Ping! Pong! Time taken: %d milliseconds\n", time_taken);

    // Close the socket
    close(sockfd);

    return 0;
}