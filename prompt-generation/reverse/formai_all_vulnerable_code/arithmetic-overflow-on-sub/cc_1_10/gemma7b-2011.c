//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

int main()
{

    // Declare variables
    int sockfd, n, i, j, k;
    char buf[1024], hostname[256], ping_reply[1024];
    struct sockaddr_in servaddr;
    struct hostent *hp;
    time_t tstart, tend, elapsed;

    // Get the hostname
    printf("Enter the hostname: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, htons(8));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Send a ping message
    tstart = time(NULL);
    send(sockfd, "PING", 5, 0);

    // Receive the ping reply
    n = recv(sockfd, ping_reply, 1024, 0);

    // Calculate the elapsed time
    tend = time(NULL);
    elapsed = tend - tstart;

    // Print the ping reply
    printf("Ping reply: %s\n", ping_reply);

    // Print the elapsed time
    printf("Elapsed time: %ld milliseconds\n", elapsed);

    // Close the socket
    close(sockfd);

    return 0;
}