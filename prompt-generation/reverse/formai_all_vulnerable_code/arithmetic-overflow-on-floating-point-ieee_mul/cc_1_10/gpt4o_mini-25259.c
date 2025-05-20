//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_IP "127.0.0.1" // Test server IP or hostname
#define SERVER_PORT 8080
#define BUFFER_SIZE 8192 // Size of data buffer for transferring

void error_exit(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void perform_speed_test() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long total_bytes = 0;
    ssize_t bytes_sent, bytes_received;
    time_t start_time, end_time;
    
    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        error_exit("Socket creation failed");
    }

    // Setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    
    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error_exit("Invalid address/Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_exit("Connection failed");
    }

    // Download speed test
    printf("Starting Download Speed Test...\n");
    start_time = time(NULL);
    
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        total_bytes += bytes_received;
    }

    if (bytes_received < 0) {
        error_exit("Error receiving data");
    }
    
    end_time = time(NULL);
    double download_time = difftime(end_time, start_time);
    double download_speed = (total_bytes * 8) / (download_time * 1e6); // Mbps

    // Print result of download speed
    printf("Download Speed: %.2f Mbps\n", download_speed);

    // Upload speed test
    total_bytes = 0;
    printf("Starting Upload Speed Test...\n");
    start_time = time(NULL);

    // Prepare a buffer to upload
    memset(buffer, 'A', BUFFER_SIZE);
    
    for (int i = 0; i < 100; i++) { // Send 100 chunks
        bytes_sent = send(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_sent < 0) {
            error_exit("Error sending data");
        }
        total_bytes += bytes_sent;
    }

    end_time = time(NULL);
    double upload_time = difftime(end_time, start_time);
    double upload_speed = (total_bytes * 8) / (upload_time * 1e6); // Mbps

    // Print result of upload speed
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    // Close the socket 
    close(sock);
}

int main() {
    printf("Internet Speed Test Application\n");
    printf("===============================\n");

    perform_speed_test();

    return 0;
}