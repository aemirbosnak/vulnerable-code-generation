//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define URL "www.example.com"
#define PORT 80

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void get_request(char *request) {
    sprintf(request, "GET / HTTP/1.1\r\n"
                     "Host: %s\r\n"
                     "Connection: close\r\n"
                     "\r\n", URL);
}

double download_file(int sockfd) {
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;
    size_t total_bytes = 0;
    
    time_t start_time = time(NULL);
    
    while ((bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_read;
    }
    
    if (bytes_read < 0) {
        error("recv failed");
    }
    
    time_t end_time = time(NULL);
    
    return (double) total_bytes / (end_time - start_time);
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[256];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    // Setting up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // IP for www.example.com
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }
    
    // Send HTTP GET request
    get_request(request);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("ERROR sending request");
    }
    
    // Measure download speed
    double speed = download_file(sockfd);
    
    // Display the download speed in KB/s
    printf("Download Speed: %.2f KB/s\n", speed / 1024);
    
    // Close the socket
    close(sockfd);
    return 0;
}