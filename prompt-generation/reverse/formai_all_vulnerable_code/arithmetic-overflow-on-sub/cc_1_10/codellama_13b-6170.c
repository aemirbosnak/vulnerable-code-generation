//Code Llama-13B DATASET v1.0 Category: Internet Speed Test Application ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define HOST "speedtest.net"
#define PORT 80

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval start, end;
    char buf[BUFSIZE];
    double time_elapsed;
    int sent = 0, received = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(HOST);
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Send a request to the server
    send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);

    // Receive the response from the server
    while (received < BUFSIZE) {
        int n = recv(sockfd, buf + received, BUFSIZE - received, 0);
        if (n < 0) {
            perror("recv failed");
            exit(1);
        }
        received += n;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the time elapsed
    time_elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

    // Print the result
    printf("Time elapsed: %f ms\n", time_elapsed);

    // Close the socket
    close(sockfd);

    return 0;
}