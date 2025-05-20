//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SERVER_PORT 5000
#define MAX_PINGS 10

int main()
{
    int sockfd, i, j, err, nsent, nrecv, ping_num = 0, server_fd;
    char buffer[1024], ping_message[256], server_address[16];
    struct sockaddr_in server_addr;

    // Get the server address from the user
    printf("Enter the server address: ");
    scanf("%s", server_address);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_fd = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (server_fd < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send and receive ping messages
    for (i = 0; i < MAX_PINGS; i++)
    {
        // Generate a ping message
        sprintf(ping_message, "Ping %d", ping_num);

        // Send the ping message
        nsent = send(server_fd, ping_message, strlen(ping_message), 0);
        if (nsent < 0)
        {
            perror("Error sending ping message");
            exit(1);
        }

        // Receive the ping message
        nrecv = recv(server_fd, buffer, sizeof(buffer), 0);
        if (nrecv < 0)
        {
            perror("Error receiving ping message");
            exit(1);
        }

        // Print the ping message
        printf("Received: %s\n", buffer);

        // Increment the ping number
        ping_num++;
    }

    // Close the socket
    close(sockfd);

    return 0;
}