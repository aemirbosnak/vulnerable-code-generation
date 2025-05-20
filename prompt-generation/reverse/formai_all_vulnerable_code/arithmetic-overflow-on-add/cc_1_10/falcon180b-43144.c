//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFLEN 1024
#define SERVER "speedtest.net"
#define PORT 80

int main()
{
    int sockfd, bytes_sent, bytes_received, total_bytes_received = 0;
    char send_buf[BUFLEN], recv_buf[BUFLEN];
    struct sockaddr_in server_addr;
    double start_time, end_time;
    double elapsed_time, bandwidth;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    // Send request
    strcpy(send_buf, "GET / HTTP/1.1\r\nHost: speedtest.net\r\nConnection: close\r\n\r\n");
    bytes_sent = send(sockfd, send_buf, strlen(send_buf), 0);
    if (bytes_sent == -1)
    {
        printf("Error sending request\n");
        close(sockfd);
        return 1;
    }

    // Receive response
    bytes_received = 0;
    start_time = time(NULL);
    while (bytes_received < BUFLEN - 1)
    {
        bytes_received += recv(sockfd, recv_buf + bytes_received, BUFLEN - bytes_received - 1, 0);
    }
    total_bytes_received += bytes_received;
    end_time = time(NULL);

    // Calculate bandwidth
    elapsed_time = difftime(end_time, start_time);
    bandwidth = (double)total_bytes_received / elapsed_time;

    // Print results
    printf("Bandwidth: %.2lf kbps\n", bandwidth / 1024);

    close(sockfd);
    return 0;
}