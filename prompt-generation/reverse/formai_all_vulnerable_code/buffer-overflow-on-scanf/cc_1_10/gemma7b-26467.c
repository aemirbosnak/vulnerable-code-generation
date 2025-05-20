//Gemma-7B DATASET v1.0 Category: Website Uptime Monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define HOST "localhost"
#define PORT 8080

int main()
{
    int sockfd, n, bytes_read, flag = 0;
    struct sockaddr_in serv_addr;
    char buf[1024];
    time_t tstart, tend, total_time;

    // Socket setup
    sockfd = socket(AF_INET, SOCK_STREAM, htons(PORT));
    if (sockfd < 0)
    {
        perror("Error creating socket");
        exit(1);
    }

    // Connect to the server
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(HOST);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        perror("Error connecting to server");
        exit(1);
    }

    // Start timer
    tstart = time(NULL);

    // Send a message to the server
    printf("Enter a message: ");
    scanf("%s", buf);
    write(sockfd, buf, strlen(buf) + 1);

    // Receive a message from the server
    bytes_read = read(sockfd, buf, 1024);
    if (bytes_read > 0)
    {
        printf("Server's response: %s\n", buf);
    }

    // End timer
    tend = time(NULL);
    total_time = tend - tstart;

    // Print total time
    printf("Total time: %ld seconds\n", total_time);

    // Close the socket
    close(sockfd);

    return 0;
}