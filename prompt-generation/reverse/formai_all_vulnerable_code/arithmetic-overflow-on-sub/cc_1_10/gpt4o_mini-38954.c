//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define SERVER_IP "your_server_ip_here" // Replace with the server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_COUNT 5

// Function to measure the time taken for the download
double downloadSpeedTest(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start, end;
    size_t bytes_received = 0;
    
    // Start the timer
    gettimeofday(&start, NULL);
    
    while(1) {
        ssize_t bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes <= 0) break;  // Break on connection loss or error
        bytes_received += bytes;
    }
    
    // Stop the timer
    gettimeofday(&end, NULL);
    
    // Calculate time taken in seconds
    double time_taken = (end.tv_sec - start.tv_sec) + 
                        (end.tv_usec - start.tv_usec) / 1e6;

    return (bytes_received * 8) / (time_taken * 1000000); // Mbps
}

int main() {
    struct sockaddr_in server_addr;
    int sockfd;
    double speed;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Starting Internet Speed Test...\n");
    
    for (int i = 0; i < TEST_COUNT; i++) {
        printf("Test #%d: ", i + 1);
        
        // Send a request to the server to begin the download test
        send(sockfd, "GET /test-file HTTP/1.1\r\nHost: " SERVER_IP "\r\n\r\n", 0, 0);
        
        // Measure download speed
        speed = downloadSpeedTest(sockfd);
        
        if (speed < 0) {
            printf("Error occurred during download speed measurement.\n");
        } else {
            printf("Download Speed: %.2f Mbps\n", speed);
        }

        // Sleep for a second between tests
        sleep(1);
    }

    // Close the socket
    close(sockfd);
    
    return 0;
}