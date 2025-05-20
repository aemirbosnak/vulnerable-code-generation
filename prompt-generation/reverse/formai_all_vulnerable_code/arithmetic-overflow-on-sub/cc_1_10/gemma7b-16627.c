//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: complete
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <time.h>

#define SERVER_NAME "localhost"
#define SERVER_PORT 8080

int main()
{

    int sockfd, port, n, i, status;
    struct sockaddr_in servaddr;
    char buffer[1024];
    time_t start, end;

    // Socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Server address and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    servaddr.sin_addr.s_addr = inet_addr(SERVER_NAME);

    // Connect to server
    status = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (status < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Timing start
    start = time(NULL);

    // Sending and receiving data
    n = write(sockfd, "HELLO WORLD!", 13);
    if (n < 0)
    {
        perror("Error sending data");
        exit(1);
    }

    n = read(sockfd, buffer, 1024);
    if (n < 0)
    {
        perror("Error receiving data");
        exit(1);
    }

    // Timing end
    end = time(NULL);

    // Print data and timing
    printf("Received data: %s\n", buffer);
    printf("Time taken: %ld seconds\n", end - start);

    // Close socket
    close(sockfd);

    return 0;
}