//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_HOST "localhost"
#define SERVER_PORT 8080

int main()
{
    int sockfd, port, n, bytes_sent, bytes_received;
    struct sockaddr_in serv_addr;
    char msg[1024] = "Hello, world!";
    struct timespec start, end;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(IPPROTO_UDP));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_HOST);

    // Start the timer
    clock_gettime(CLOCK_REALTIME, &start);

    // Send the message
    bytes_sent = sendto(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (bytes_sent < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive the message
    bytes_received = recvfrom(sockfd, msg, sizeof(msg), 0, (struct sockaddr *)&serv_addr, NULL);
    if (bytes_received < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Stop the timer
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate the time taken
    n = end.tv_sec - start.tv_sec;
    printf("Time taken: %d seconds\n", n);

    // Print the received message
    printf("Received message: %s\n", msg);

    // Close the socket
    close(sockfd);

    return 0;
}