//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    char hostname[256];
    char message[256];
    int sockfd, result, i, j, ping_status = 0;

    // Get the hostname from the user
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8888);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    result = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send a message
    printf("Enter your message: ");
    scanf("%s", message);
    write(sockfd, message, strlen(message) + 1);

    // Receive a response
    char response[256];
    read(sockfd, response, 256);

    // Print the response
    printf("Received response: %s\n", response);

    // Close the socket
    close(sockfd);

    // Check if the ping was successful
    if (strcmp(response, "pong") == 0)
    {
        ping_status = 1;
    }

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