//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: mathematical
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    struct sockaddr_in server_addr;
    int sockfd, bytes_received;
    char buffer[BUFFER_SIZE];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    if (inet_aton("127.0.0.1", &server_addr.sin_addr) == 0) {
        perror("Error setting server address");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send request to server
    char *request = "GET / HTTP/1.0\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(1);
    }

    // Set timeval structs for measuring time
    struct timeval start_time;
    struct timeval end_time;

    // Start timer
    gettimeofday(&start_time, NULL);

    // Read response from server
    bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        // Update bytes received
        bytes_received += bytes_received;
    }

    // Stop timer
    gettimeofday(&end_time, NULL);

    // Print results
    double elapsed_time = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    printf("Elapsed time: %f seconds\n", elapsed_time);
    double download_speed = (double)bytes_received / elapsed_time;
    printf("Download speed: %f bytes/second\n", download_speed);

    // Close socket
    close(sockfd);

    return 0;
}