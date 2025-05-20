//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <netdb.h>

#define SERVER_PORT 8888

int main()
{
    int sockfd, nbytes, i, port, client_port;
    char buffer[1024];
    struct sockaddr_in server_addr, client_addr;
    clock_t start, end;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error binding socket.\n");
        exit(1);
    }

    // Listen for clients
    while (1)
    {
        // Accept a client connection
        client_addr.sin_port = htons(port);
        nbytes = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
        if (nbytes < 0)
        {
            printf("Error accepting client connection.\n");
            continue;
        }

        // Start the clock
        start = clock();

        // Send a message to the client
        printf("Enter a message: ");
        scanf("%s", buffer);
        send(sockfd, buffer, nbytes, 0);

        // Receive a message from the client
        nbytes = recv(sockfd, buffer, 1024, 0);
        if (nbytes > 0)
        {
            // End the clock
            end = clock();

            // Calculate the time taken
            int time_taken = end - start;

            // Print the message from the client
            printf("Received message: %s\n", buffer);

            // Print the time taken
            printf("Time taken: %d milliseconds\n", time_taken);
        }

        // Close the client connection
        close(sockfd);
    }

    return 0;
}