//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1" // Change this to your server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void display_welcome_message() {
    printf("===================================\n");
    printf("       Internet Speed Test         \n");
    printf("===================================\n");
    printf("Testing your internet speed...\n");
}

void display_results(double download_speed, double upload_speed) {
    printf("===================================\n");
    printf("           Test Results            \n");
    printf("===================================\n");
    printf("Download Speed: %.2f Mbps\n", download_speed);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);
    printf("===================================\n");
}

double measure_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    double total_bytes = 0;
    time_t start_time = time(NULL);

    while (time(NULL) - start_time < TEST_DURATION) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received < 0) {
            perror("Error receiving data");
            exit(EXIT_FAILURE);
        }
        total_bytes += bytes_received;
    }

    double seconds_elapsed = difftime(time(NULL), start_time);
    return (total_bytes * 8) / (seconds_elapsed * 1024 * 1024); // convert to Mbps
}

double measure_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'x', sizeof(buffer)); // fill buffer with dummy data
    double total_bytes = 0;
    time_t start_time = time(NULL);

    while (time(NULL) - start_time < TEST_DURATION) {
        int bytes_sent = send(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_sent < 0) {
            perror("Error sending data");
            exit(EXIT_FAILURE);
        }
        total_bytes += bytes_sent;
    }

    double seconds_elapsed = difftime(time(NULL), start_time);
    return (total_bytes * 8) / (seconds_elapsed * 1024 * 1024); // convert to Mbps
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    display_welcome_message();

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Measure download speed
    printf("Measuring download speed...\n");
    double download_speed = measure_download_speed(sockfd);

    // Measure upload speed
    printf("Measuring upload speed...\n");
    double upload_speed = measure_upload_speed(sockfd);

    // Display results
    display_results(download_speed, upload_speed);

    // Cleanup
    close(sockfd);
    return EXIT_SUCCESS;
}