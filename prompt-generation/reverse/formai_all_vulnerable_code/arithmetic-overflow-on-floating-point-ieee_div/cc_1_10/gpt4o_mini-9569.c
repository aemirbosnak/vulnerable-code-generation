//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER "http://ipv4.download.thinkbroadband.com/10MB.zip"  // URL for file to download
#define PORT 80
#define BUFFER_SIZE 8192

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void download_file(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[1024], response[BUFFER_SIZE];
    int bytes_received;
    struct timeval start, end;
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // Prepare HTTP GET request
    snprintf(request, sizeof(request), "GET /10MB.zip HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);
    
    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0)
        error("ERROR sending request");

    // Start timer
    gettimeofday(&start, NULL);

    // Receive the response
    int total_bytes = 0;
    while ((bytes_received = recv(sockfd, response, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }
    
    // End timer
    gettimeofday(&end, NULL);
    
    // Close the socket
    close(sockfd);

    // Calculate elapsed time in seconds
    double elapsed = (end.tv_sec - start.tv_sec) * 1.0 + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate speed in Mbps
    double speed_mbps = (total_bytes * 8) / (elapsed * 1000000);
    
    printf("Downloaded %d bytes in %.2f seconds\n", total_bytes, elapsed);
    printf("Speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    // Extract hostname from URL
    char hostname[256];
    strcpy(hostname, "ipv4.download.thinkbroadband.com");

    printf("Starting internet speed test...\n");
    download_file(hostname);
    return 0;
}