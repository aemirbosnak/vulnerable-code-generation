//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>

// Function to measure download speed
double measure_download_speed(const char* url, size_t buffer_size) {
    int sockfd;
    struct sockaddr_in server_addr;
    char* buffer = malloc(buffer_size);
    struct timeval start, end;
    size_t total_bytes = 0;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP default port

    // Convert URL to IP address (basic implementation, requires proper handling)
    server_addr.sin_addr.s_addr = inet_addr(url); // This should be replaced with gethostbyname in a real application

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start timing
    gettimeofday(&start, NULL);
    
    // Send GET request
    char request[1024];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);
    send(sockfd, request, strlen(request), 0);

    // Read the response
    while (recv(sockfd, buffer, buffer_size, 0) > 0) {
        total_bytes += buffer_size;
    }
    
    // Stop timing
    gettimeofday(&end, NULL);
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate speed
    double speed_mbps = (total_bytes * 8) / (elapsed_time * 1000000); // Convert bytes to Megabits
    
    // Cleanup
    free(buffer);
    close(sockfd);
    
    return speed_mbps;
}

// Function to print the results
void print_results(const char* url) {
    printf("Testing download speed to %s...\n", url);
    double speed = measure_download_speed(url, 1024);
    printf("Download speed: %.2f Mbps\n", speed);
}

// Main function
int main() {
    const char* test_url = "93.184.216.34"; // Example IP for example.com
    print_results(test_url);
    return 0;
}