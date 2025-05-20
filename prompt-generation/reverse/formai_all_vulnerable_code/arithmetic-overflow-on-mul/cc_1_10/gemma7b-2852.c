//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_NAME "192.168.1.1"
#define SERVER_PORT 8080

int main()
{
    int sockfd, ret, n, i, j;
    struct sockaddr_in server_addr;
    char buffer[1024];
    time_t start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_NAME);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Send a ping message
    n = write(sockfd, "PING", 5);

    // Receive the ping response
    n = read(sockfd, buffer, 1024);

    // Print the ping response
    printf("Received: %s\n", buffer);

    // Calculate the time taken for the ping
    start_time = time(NULL);
    end_time = time(NULL);

    j = end_time - start_time;

    // Print the time taken for the ping
    printf("Time taken: %d milliseconds\n", j * 1000);

    // Close the socket
    close(sockfd);

    return 0;
}