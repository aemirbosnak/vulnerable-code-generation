//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/tcp.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

// Function to calculate the round trip time of the packet
float GetRTT(struct timeval start, struct timeval end)
{
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}

// Main function
int main(int argc, char *argv[])
{
    // Check if proper arguments are given
    if (argc < 2)
    {
        printf("Usage: %s <hostname/IP address> <port(optional)>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = 80;

    // Check if port is provided in arguments
    if (argc == 3)
    {
        port = atoi(argv[2]);
    }

    // Allocate memory for hostent structure
    struct hostent *server = (struct hostent*) malloc(sizeof(struct hostent));

    // Get the host information using gethostbyname function
    server = gethostbyname(hostname);

    // Check if host exists
    if (server == NULL)
    {
        printf("Host not found.");
        exit(1);
    }

    // Create a socket using socket function
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket is successfully created
    if (sockfd < 0)
    {
        printf("Error opening socket.");
        exit(1);
    }

    // Define the server address structure
    struct sockaddr_in serv_addr;

    // Clear the buffer for server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Set the server address structure values
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    // Connect to the server using connect() function
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error connecting.");
        exit(1);
    }

    // Set the TCP_NODELAY option to disable Nagle's algorithm
    int flag = 1;
    int result = setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));

    // Check if option is successfully set
    if (result < 0)
    {
        printf("Error setting option.");
        exit(1);
    }

    char buffer[MAX_BUF_SIZE];
    float rtt_total = 0.0;
    int num_pings = 10;

    // Do 10 pings to the server and calculate the average RTT
    for (int i = 0; i < num_pings; i++)
    {
        struct timeval start, end;

        // Get the current time for calculating RTT
        gettimeofday(&start, NULL);

        // Send a dummy message to the server
        result = send(sockfd, "PING", 4, 0);

        // Check if message is successfully sent
        if (result < 0)
        {
            printf("Error sending message.");
            exit(1);
        }

        // Receive the response message from the server
        result = recv(sockfd, buffer, MAX_BUF_SIZE, 0);

        // Check if message is successfully received
        if (result < 0)
        {
            printf("Error receiving message.");
            exit(1);
        }

        // Get the current time again for calculating RTT
        gettimeofday(&end, NULL);

        // Calculate and add the RTT to the total
        float rtt = GetRTT(start, end);
        rtt_total += rtt;

        printf("PING %d: RTT = %.3f ms\n", i+1, rtt);
        
        // Wait for 1 second before sending the next message
        sleep(1);
    }

    // Calculate the average RTT of all the pings
    float avg_rtt = rtt_total / num_pings;
    printf("\nAverage RTT = %.3f ms\n", avg_rtt);

    // Close the socket connection
    close(sockfd);

    return 0;
}