//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define PORT_SCAN_RANGE 1024

int main()
{
    int sockfd, port, i, scan_port, target_port, err;
    char buffer[1024];
    struct sockaddr_in sock_addr;
    struct hostent *host;

    // Get the target host name
    char target_host[256];
    printf("Enter the target host name: ");
    scanf("%s", target_host);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        return 1;
    }

    // Resolve the target host
    host = gethostbyname(target_host);
    if (host == NULL)
    {
        perror("Error resolving host");
        return 1;
    }

    // Set up the socket address
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = host->h_addr_list[0];

    // Scan the ports
    for (scan_port = 0; scan_port < PORT_SCAN_RANGE; scan_port++)
    {
        // Connect to the port
        if (connect(sockfd, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) == 0)
        {
            // Port is open
            printf("Port %d is open.\n", scan_port);

            // Send a message to the port
            sprintf(buffer, "Hello, world!");
            send(sockfd, buffer, strlen(buffer), 0);

            // Receive a message from the port
            recv(sockfd, buffer, sizeof(buffer), 0);
            printf("Received: %s\n", buffer);

            // Close the connection
            close(sockfd);
        }
    }

    return 0;
}