//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

int main()
{
    char hostname[256];
    int sockfd, n, i, recv_len;
    struct sockaddr_in server_addr;

    printf("Enter the hostname of the server: ");
    scanf("%s", hostname);

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
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    printf("Enter a message: ");
    scanf("%s", hostname);

    n = send(sockfd, hostname, sizeof(hostname), 0);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message from the server
    recv_len = recv(sockfd, hostname, sizeof(hostname), 0);
    if (recv_len < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", hostname);

    // Close the socket
    close(sockfd);

    return 0;
}