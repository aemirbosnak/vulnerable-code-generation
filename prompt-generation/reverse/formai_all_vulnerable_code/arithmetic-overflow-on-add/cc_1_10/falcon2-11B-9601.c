//Falcon2-11B DATASET v1.0 Category: Website Uptime Monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    struct timeval start, end;
    char buffer[1024];
    char hostname[256];
    int port = 80;
    int sockfd;
    struct sockaddr_in serveraddr;
    int n;

    // Get current time
    gettimeofday(&start, NULL);

    // Open a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    if (inet_pton(AF_INET, "www.example.com", &serveraddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read from the socket
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("read");
        exit(1);
    }

    // Get current time
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    long int diff = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;

    // Print the result
    printf("Website Uptime: %ld ms\n", diff);

    // Close the socket
    close(sockfd);

    return 0;
}