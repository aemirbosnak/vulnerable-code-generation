//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080

int main()
{
    int sockfd, n, i, flag = 0;
    struct sockaddr_in server_addr;
    char buffer[1024];
    time_t t = time(NULL);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send a message to the server
    printf("Enter your message: ");
    scanf("%s", buffer);
    send(sockfd, buffer, sizeof(buffer), 0);

    // Receive a message from the server
    n = recv(sockfd, buffer, sizeof(buffer), 0);

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sockfd);

    // Calculate the time taken for the transaction
    t = time(NULL) - t;

    // Print the time taken
    printf("Time taken: %d seconds\n", t);

    // Check if the server is still up
    if (n < 0)
    {
        flag = 1;
    }

    // If the server is not up, print an error message
    if (flag)
    {
        printf("Error: Server is down.\n");
    }

    return 0;
}