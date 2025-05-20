//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: cheerful
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int sockfd, port, n, i, flag = 0;
    char buffer[1024];
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the port number from the user
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    printf("Enter your message: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer) + 1, 0);

    // Receive a message from the server
    n = recv(sockfd, buffer, 1024, 0);

    // Print the message from the server
    printf("Message from the server: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}