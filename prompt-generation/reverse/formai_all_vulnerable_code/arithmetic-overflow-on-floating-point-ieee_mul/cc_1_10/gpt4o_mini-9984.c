//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>
#include <netinet/in.h>

#define SERVER_ADDRESS "speed.hetzner.de" // Speed test server
#define PORT 80 // HTTP port
#define BUF_SIZE 1024 // Buffer size for data

void measure_speed(int sockfd);
void print_results(double download_speed, double upload_speed, double time_taken);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Connected to %s on port %d...\n", SERVER_ADDRESS, PORT);
    
    measure_speed(sockfd);

    close(sockfd);
    return 0;
}

void measure_speed(int sockfd) {
    char buffer[BUF_SIZE];
    size_t total_bytes = 0;
    time_t start, end;

    // Start the download speed test
    printf("Downloading data...\n");
    start = time(NULL);

    // Simulate data reception (for speed testing)
    while (total_bytes < 10485760) { // 10 MB
        ssize_t bytes_received = recv(sockfd, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            perror("Receive error or connection closed");
            break;
        }
        total_bytes += bytes_received;
    }
    
    end = time(NULL);
    double time_taken = difftime(end, start);
    double download_speed = total_bytes / (time_taken * 1024.0); // KB/s

    printf("Download complete. Download speed: %.2f KB/s\n", download_speed);

    // Now for upload speed (simulate upload)
    total_bytes = 0;
    start = time(NULL);
    printf("Uploading data...\n");

    // Simulate upload (sending data)
    while (total_bytes < 10485760) { // 10 MB
        ssize_t bytes_sent = send(sockfd, buffer, BUF_SIZE, 0);
        if (bytes_sent <= 0) {
            perror("Send error or connection closed");
            break;
        }
        total_bytes += bytes_sent;
    }
    
    end = time(NULL);
    time_taken = difftime(end, start);
    double upload_speed = total_bytes / (time_taken * 1024.0); // KB/s

    printf("Upload complete. Upload speed: %.2f KB/s\n", upload_speed);
    print_results(download_speed, upload_speed, time_taken);
}

void print_results(double download_speed, double upload_speed, double time_taken) {
    printf("\n==== Speed Test Results ====\n");
    printf("Total time taken: %.2fs\n", time_taken);
    printf("Download Speed: %.2f KB/s\n", download_speed);
    printf("Upload Speed: %.2f KB/s\n", upload_speed);
    printf("=============================\n");
}