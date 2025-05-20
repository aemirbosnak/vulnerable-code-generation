//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>

int main()
{
    char hostname[256];
    int sockfd, ping_status;
    struct sockaddr_in serv_addr;

    printf("Enter the hostname of the target machine: ");
    scanf("%s", hostname);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the target machine
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(5000);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to the target machine");
        exit(1);
    }

    // Send a ping packet
    write(sockfd, "PING", 5);

    // Receive the ping response
    ping_status = read(sockfd, hostname, 256);

    // Print the ping status
    if (ping_status > 0)
    {
        printf("The target machine is alive: %s\n", hostname);
    }
    else
    {
        printf("The target machine is not alive.\n");
    }

    // Close the socket
    close(sockfd);

    return 0;
}