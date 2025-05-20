//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: complex
/*
 * A simple socket programming example program in a complex style
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc, char **argv)
{
    // Check if the user has provided the correct number of arguments
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("connect");
        exit(1);
    }

    // Send a message to the server
    char message[] = "Hello, server!";
    if (send(sock, message, strlen(message), 0) < 0)
    {
        perror("send");
        exit(1);
    }

    // Receive a message from the server
    char buffer[1024];
    if (recv(sock, buffer, sizeof(buffer), 0) < 0)
    {
        perror("recv");
        exit(1);
    }

    // Print the received message
    printf("Received message from server: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}