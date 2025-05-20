//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_IP "192.168.1.1"  // Set the IP address of the server to test
#define SERVER_PORT 8080        // Set the port number of the server to test
#define BUFFER_SIZE 1024        // Set the buffer size for sending and receiving data

int main()
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error connecting to the server");
        exit(EXIT_FAILURE);
    }

    // Send data to the server
    memset(buffer, 0, BUFFER_SIZE);
    strcpy(buffer, "Hello from client!");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending data to the server");
        exit(EXIT_FAILURE);
    }

    // Receive data from the server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0)
    {
        perror("Error receiving data from the server");
        exit(EXIT_FAILURE);
    }

    // Calculate the time taken for the round-trip
    struct timeval start, end;
    gettimeofday(&start, NULL);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0)
    {
        perror("Error sending data to the server");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&end, NULL);
    long time_taken = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

    // Calculate the speed in bits per second
    int speed = (BUFFER_SIZE * 8) / time_taken;

    // Print the speed
    printf("Speed: %d bps\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}