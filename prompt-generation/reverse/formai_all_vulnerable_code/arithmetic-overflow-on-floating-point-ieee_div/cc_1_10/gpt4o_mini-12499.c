//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_IP "192.168.1.1"  // Replace with your server IP for testing
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void display_welcome_message() {
    printf("========================================\n");
    printf("      Internet Speed Test Application    \n");
    printf("========================================\n");
    printf("This application measures your internet speed.\n");
    printf("The test sends and receives data from a server.\n");
    printf("Make sure to have the server running on the specified IP.\n\n");
}

double measure_download_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'A', BUFFER_SIZE); // Fill buffer with data
    buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the string

    size_t bytes_sent = 0;
    ssize_t bytes_received;
    time_t start_time, end_time;

    // Start measuring time
    start_time = time(NULL);
    while (bytes_sent < BUFFER_SIZE) {
        ssize_t sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (sent < 0) {
            error("Error sending data.");
        }
        bytes_sent += sent;
    }

    // Receive the data back and measure the time taken
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        error("Error receiving data.");
    }

    end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    return (bytes_received / time_taken) / (1024.0); // Return speed in KB/s
}

double measure_upload_speed(int sockfd) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 'B', BUFFER_SIZE); // Fill buffer with data
    buffer[BUFFER_SIZE - 1] = '\0'; // Null-terminate the string

    size_t bytes_sent = 0;
    time_t start_time, end_time;

    // Start measuring time
    start_time = time(NULL);
    while (bytes_sent < BUFFER_SIZE) {
        ssize_t sent = send(sockfd, buffer, BUFFER_SIZE, 0);
        if (sent < 0) {
            error("Error sending data.");
        }
        bytes_sent += sent;
    }
    
    end_time = time(NULL);
    double time_taken = difftime(end_time, start_time);

    return (bytes_sent / time_taken) / (1024.0); // Return speed in KB/s
}

int main() {
    display_welcome_message();

    int sockfd;
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    // Setup server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported.");
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed.");
    }

    // Measure download speed
    printf("Measuring download speed...\n");
    double download_speed = measure_download_speed(sockfd);
    printf("Download Speed: %.2f KB/s\n", download_speed);

    // Measure upload speed
    printf("Measuring upload speed...\n");
    double upload_speed = measure_upload_speed(sockfd);
    printf("Upload Speed: %.2f KB/s\n", upload_speed);

    // Close the socket
    close(sockfd);
    printf("Speed test complete. Thank you for using the application.\n");
    return 0;
}