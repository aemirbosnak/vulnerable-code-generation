//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define HOSTNAME "localhost"
#define PORT 8080

void main()
{
    int sockfd, n, recv_len;
    struct sockaddr_in serv_addr;
    char buffer[1024];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd == -1)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(HOSTNAME);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start the timer
    start_time = time(NULL);

    // Send a message to the server
    printf("Enter a message: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer) + 1, 0);

    // Receive a message from the server
    recv_len = recv(sockfd, buffer, 1024, 0);

    // End the timer
    end_time = time(NULL);

    // Print the received message
    printf("Received: %s\n", buffer);

    // Calculate the time taken
    n = (end_time - start_time) * 1000;
    printf("Time taken: %.2f ms\n", n);

    // Close the socket
    close(sockfd);

    return;
}