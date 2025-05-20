//Gemma-7B DATASET v1.0 Category: Network Ping Test ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define SERVER_NAME "192.168.1.10"
#define SERVER_PORT 8080

int main()
{
    int sockfd, err, i, j;
    struct sockaddr_in server_addr;
    char buf[1024];
    time_t start, end;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0)
    {
        perror("Socket error");
        exit(1);
    }

    // Server address setup
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_NAME, &server_addr.sin_addr);

    // Connection attempt
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Connection error");
        exit(1);
    }

    // Time measurement start
    start = time(NULL);

    // Ping message exchange
    for (i = 0; i < 10; i++)
    {
        printf("Sending ping...\n");
        write(sockfd, "PING", 5);

        // Receive response
        read(sockfd, buf, 1024);
        printf("Received response: %s\n", buf);
    }

    // Time measurement end
    end = time(NULL);

    // Calculate ping time
    int ping_time = (end - start) * 1000;

    // Print results
    printf("Total time: %d milliseconds\n", ping_time);
    printf("Average ping time: %d milliseconds\n", ping_time / 10);

    // Close connection
    close(sockfd);

    return 0;
}