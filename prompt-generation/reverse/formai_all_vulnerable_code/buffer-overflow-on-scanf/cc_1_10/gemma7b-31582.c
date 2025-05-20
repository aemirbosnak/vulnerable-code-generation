//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>

int main()
{
    char hostname[256];
    int sockfd, ping_status = 0;
    struct sockaddr_in servaddr;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a ping message
    char ping_message[] = "PING";
    send(sockfd, ping_message, strlen(ping_message), 0);

    // Receive the ping reply
    char reply[1024];
    recv(sockfd, reply, sizeof(reply), 0);

    // Check if the ping reply is successful
    if (strcmp(reply, "PONG") == 0)
    {
        ping_status = 1;
    }

    // Close the socket
    close(sockfd);

    // Print the ping status
    if (ping_status)
    {
        printf("Ping successful!\n");
    }
    else
    {
        printf("Ping failed.\n");
    }

    return 0;
}