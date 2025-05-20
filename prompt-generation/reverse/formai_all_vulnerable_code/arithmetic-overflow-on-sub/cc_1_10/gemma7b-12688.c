//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080

int main()
{
    int sockfd, newsockfd, clientlen, i, j, k;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024];
    time_t start, end;
    int timeout = 5;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    while (1)
    {
        clientlen = sizeof(client_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);

        // Check if the client is alive
        start = time(NULL);
        send(newsockfd, "PING", 5, 0);
        k = recv(newsockfd, buffer, 1024, 0);
        end = time(NULL);

        // Calculate the time taken for the ping
        int time_taken = end - start;

        // Print the time taken
        printf("Client: %s, Time taken: %d milliseconds\n", inet_ntoa(client_addr), time_taken);

        // Close the connection
        close(newsockfd);
    }

    return 0;
}