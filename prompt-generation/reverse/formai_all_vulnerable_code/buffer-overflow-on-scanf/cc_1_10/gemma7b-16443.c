//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, port, n, err, i, j;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server_host;

    printf("Prepare for a shocking C Network Ping Test!\n");

    // Get the server's hostname or IP address
    char server_name[256];
    printf("Enter the server's hostname or IP address: ");
    scanf("%s", server_name);

    // Get the server's port number
    int port_num;
    printf("Enter the server's port number: ");
    scanf("%d", &port_num);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(port_num));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_num);
    server_addr.sin_addr.s_addr = inet_addr(server_name);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a message to the server
    printf("Enter your message: ");
    scanf("%s", buffer);

    n = send(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (n < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message from the server
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (n < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the server's message
    printf("Server's response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}