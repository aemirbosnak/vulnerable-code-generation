//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define SERVER_ADDRESS "google.com" // Example server for speed test
#define PORT 80

double measure_download_time(const char *address);
double measure_upload_time(const char *address, const char *data, size_t data_size);
void report_speed(double time_taken, size_t data_size);

int main() {
    printf("Starting Internet Speed Test...\n");

    const char *test_data = "POST /upload HTTP/1.1\r\nHost: example.com\r\nContent-Length: 10000\r\n\r\n";
    size_t upload_data_size = strlen(test_data);

    double download_time = measure_download_time(SERVER_ADDRESS);
    printf("Download Time: %.6f seconds\n", download_time);
    report_speed(download_time, 1000000); // 1MB for example

    double upload_time = measure_upload_time(SERVER_ADDRESS, test_data, upload_data_size);
    printf("Upload Time: %.6f seconds\n", upload_time);
    report_speed(upload_time, upload_data_size);

    return 0;
}

double measure_download_time(const char *address) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval start, end;
    char buffer[1024];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, address, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start download time measurement
    gettimeofday(&start, NULL);

    // Send HTTP GET request
    const char *request = "GET / HTTP/1.1\r\nHost: google.com\r\nConnection: close\r\n\r\n";
    send(sockfd, request, strlen(request), 0);

    // Receive response
    while (recv(sockfd, buffer, sizeof(buffer), 0) > 0);

    // End download time measurement
    gettimeofday(&end, NULL);
    close(sockfd);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    return time_taken;
}

double measure_upload_time(const char *address, const char *data, size_t data_size) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct timeval start, end;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Initialize server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, address, &server_addr.sin_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start upload time measurement
    gettimeofday(&start, NULL);
    
    // Send HTTP POST request
    send(sockfd, data, data_size, 0);

    // End upload time measurement
    gettimeofday(&end, NULL);
    close(sockfd);

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    return time_taken;
}

void report_speed(double time_taken, size_t data_size) {
    double speed_mbps = (data_size / 1024.0 / 1024.0) / time_taken; // Speed in Mbps
    printf("Speed: %.2f Mbps\n", speed_mbps);
}