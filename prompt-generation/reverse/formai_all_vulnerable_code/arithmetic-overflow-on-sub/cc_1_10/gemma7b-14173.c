//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: romantic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int sockfd, res, i, j, k;
    struct sockaddr_in serv_addr, client_addr;
    char buffer[1024], msg[1024];
    time_t start_time, end_time;
    double duration;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Set up the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(6);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Send a message to the server
    sprintf(msg, "Hello, world!");
    res = sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (res < 0)
    {
        perror("Error sending message");
        exit(1);
    }

    // Receive a message from the server
    res = recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *)&client_addr, NULL);
    if (res < 0)
    {
        perror("Error receiving message");
        exit(1);
    }

    // Print the received message
    printf("Received message: %s\n", buffer);

    // Measure the duration of the ping
    start_time = time(NULL);
    end_time = time(NULL);
    duration = (double)(end_time - start_time) * 1000;

    // Print the duration
    printf("Duration: %.2f milliseconds\n", duration);

    // Close the socket
    close(sockfd);

    return 0;
}