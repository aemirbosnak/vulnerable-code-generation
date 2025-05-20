//Gemma-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <time.h>

int main()
{
    system("clear");

    // Setting up the HOST and PORT numbers for the server
    char host[] = "localhost";
    int port = 8080;

    // Creating a socket descriptor
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(port));

    // Connecting to the server
    struct sockaddr_in server_addr;
    server_addr.sin_port = htons(port);
    server_addr.sin_family = AF_INET;
    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Sending a ping packet to the server
    char msg[] = "PING";
    send(sockfd, msg, sizeof(msg), 0);

    // Receiving a response from the server
    char resp[1024];
    recv(sockfd, resp, 1024, 0);

    // Displaying the server's response
    printf("Response from the server: %s\n", resp);

    // Closing the socket
    close(sockfd);

    // Measuring the time taken for the ping
    time_t start_time = time(NULL);
    time_t end_time = time(NULL);
    double time_taken = end_time - start_time;

    // Displaying the time taken
    printf("Time taken for the ping: %.2f seconds\n", time_taken);

    // Calculating the speed of the internet connection
    double speed = (1000 * 8) / time_taken;

    // Displaying the speed of the internet connection
    printf("Speed of the internet connection: %.2f Mbps\n", speed);

    return 0;
}