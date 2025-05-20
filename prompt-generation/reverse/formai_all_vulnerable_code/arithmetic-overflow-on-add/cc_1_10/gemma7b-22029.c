//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int sockfd, port, i, n;
    char buf[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Get the port number
    printf("Enter the port number: ");
    scanf("%d", &port);

    // Scan the port
    for (i = port; i <= port + 10; i++)
    {
        // Connect to the server
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        {
            perror("Error connecting to server");
            continue;
        }

        // Send and receive data
        n = write(sockfd, "Hello, world!", 13);
        if (n < 0)
        {
            perror("Error sending data");
        }

        n = read(sockfd, buf, 1024);
        if (n < 0)
        {
            perror("Error receiving data");
        }

        // Print the data
        printf("Received: %s\n", buf);

        // Close the connection
        close(sockfd);
    }

    return 0;
}