//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int total_bytes_received = 0;
    double start_time, end_time;
    double elapsed_time;
    int speed;

    if (argc!= 2)
    {
        printf("Usage: %s <server_ip>\n", argv[0]);
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    // Start timer
    start_time = time(NULL);
    while (1)
    {
        // Receive data from server
        bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0)
        {
            printf("Connection closed by server\n");
            break;
        }

        // Update total bytes received
        total_bytes_received += bytes_received;

        // Calculate speed
        if (total_bytes_received >= 1024)
        {
            end_time = time(NULL);
            elapsed_time = difftime(end_time, start_time);
            speed = (double)total_bytes_received / elapsed_time;
            printf("Current speed: %.2f KB/s\n", speed);
            start_time = end_time;
            total_bytes_received = 0;
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}