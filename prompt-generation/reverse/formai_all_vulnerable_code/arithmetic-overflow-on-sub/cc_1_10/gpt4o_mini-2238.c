//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1" // Change to actual server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 8192 // 8 KB buffer
#define TEST_TIME 10 // Time to run the test in seconds

void error_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

double get_time_difference(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
}

double calculate_speed(double bytes, double seconds) {
    return (bytes * 8) / (seconds * 1024 * 1024); // Convert to Mbps
}

void speed_test_download(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', sizeof(buffer)); // Fill buffer with data
    struct timeval start, end;

    gettimeofday(&start, NULL);
    size_t total_bytes = 0;

    for (int i = 0; i < TEST_TIME; i++) {
        ssize_t sent_bytes = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (sent_bytes < 0) {
            error_exit("Error sending data");
        }
        total_bytes += sent_bytes;

        ssize_t received_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (received_bytes < 0) {
            error_exit("Error receiving data");
        }
    }

    gettimeofday(&end, NULL);
    double time_taken = get_time_difference(start, end);
    double download_speed = calculate_speed(total_bytes, time_taken);
    printf("Download speed: %.2f Mbps\n", download_speed);
}

void speed_test_upload(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', sizeof(buffer)); // Fill buffer with data
    struct timeval start, end;

    gettimeofday(&start, NULL);
    size_t total_bytes = 0;

    for (int i = 0; i < TEST_TIME; i++) {
        ssize_t sent_bytes = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (sent_bytes < 0) {
            error_exit("Error sending data");
        }
        total_bytes += sent_bytes;
        
        // Adding a dummy recv to mimic the upload behavior
        recv(sockfd, buffer, BUFFER_SIZE, 0);
    }

    gettimeofday(&end, NULL);
    double time_taken = get_time_difference(start, end);
    double upload_speed = calculate_speed(total_bytes, time_taken);
    printf("Upload speed: %.2f Mbps\n", upload_speed);
}

int main() {
    int sockfd;
    struct sockaddr_in server_address;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_exit("Failed to create socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        close(sockfd);
        error_exit("Connection failed");
    }

    printf("Starting speed test...\n");
    speed_test_download(sockfd);
    speed_test_upload(sockfd);

    close(sockfd);
    return 0;
}