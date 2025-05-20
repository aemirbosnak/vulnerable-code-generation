//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define MAX_PINGS 5
#define BUFFER_SIZE 1024

int main()
{
    int i, j, k, sockfd, err, status, ping_count = 0, socklen = 1024;
    char buffer[BUFFER_SIZE], hostname[256], ping_message[1024];
    struct sockaddr_in servaddr;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    err = connect(sockfd, (struct sockaddr *)&servaddr, socklen);
    if (err)
    {
        perror("Error connecting to the server");
        exit(1);
    }

    // Send a ping message
    sprintf(ping_message, "Ping!");
    send(sockfd, ping_message, sizeof(ping_message), 0);

    // Receive the ping response
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // Print the ping response
    printf("Ping response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}