//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: futuristic
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

int main()
{
    int sockfd, port, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    time_t start_time, end_time, total_time;
    int packets_sent = 0, packets_received = 0;

    // Set up the server socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd < 0)
    {
        perror("Error setting up server socket");
        return -1;
    }

    // Bind the server socket to a port
    server_addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error binding server socket");
        return -1;
    }

    // Wait for a client connection
    client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);
    if (client_sockfd < 0)
    {
        perror("Error accepting client connection");
        return -1;
    }

    // Start the timer
    start_time = time(NULL);

    // Send and receive packets
    while (1)
    {
        // Send a packet
        printf("Enter message: ");
        scanf("%s", buffer);
        send(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
        packets_sent++;

        // Receive a packet
        recv(client_sockfd, buffer, MAX_BUFFER_SIZE, 0);
        packets_received++;
    }

    // End the timer
    end_time = time(NULL);
    total_time = end_time - start_time;

    // Calculate the average packet delay
    int average_delay = (packets_received - packets_sent) * total_time / packets_sent;

    // Print the results
    printf("Total time: %d seconds\n", total_time);
    printf("Number of packets sent: %d\n", packets_sent);
    printf("Number of packets received: %d\n", packets_received);
    printf("Average packet delay: %d milliseconds\n", average_delay);

    // Close the client socket
    close(client_sockfd);

    // Close the server socket
    close(sockfd);

    return 0;
}