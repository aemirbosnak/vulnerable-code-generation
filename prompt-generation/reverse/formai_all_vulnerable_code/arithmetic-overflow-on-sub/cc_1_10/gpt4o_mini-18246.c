//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define SERVER_IP "127.0.0.1" // Change this to the Speed Test Server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

// Function to calculate elapsed time
double calculate_time(struct timeval start, struct timeval end) {
    return ((end.tv_sec - start.tv_sec) * 1000.0) + ((end.tv_usec - start.tv_usec) / 1000.0);
}

// Main Speed Test Function
void test_speed() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    long total_bytes = 0;
    struct timeval start_time, end_time;

    // 1. SURPRISE - Initiating connection to the server!
    printf("✨ Connecting to the Speed Test Server at %s:%d... ✨\n", SERVER_IP, SERVER_PORT);
    
    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("⚡ Oops! Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Setting up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // 2. BOOM! Connecting to the server!
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("❌ Uh-oh! Connection failed");
        close(sock);
        exit(EXIT_FAILURE);
    }
    
    // Simulating Download Speed Test
    printf("📥 Starting download speed test...\n");
    gettimeofday(&start_time, NULL); // Start timer

    // Receiving data
    while (1) {
        ssize_t received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (received <= 0) {
            break;
        }
        total_bytes += received;
    }
    gettimeofday(&end_time, NULL); // End timer
    
    // Display download results
    double download_time = calculate_time(start_time, end_time) / 1000.0; // Convert to seconds
    printf("🚀 Download Test Completed!\n");
    printf("Total bytes received: %ld bytes\n", total_bytes);
    printf("Download Speed: %.2f Mbps\n", (total_bytes * 8.0) / (download_time * 1e6));

    // Reset total bytes for upload test
    total_bytes = 0;
    
    // Simulating Upload Speed Test
    printf("📤 Starting upload speed test...\n");
    gettimeofday(&start_time, NULL); // Start timer

    while (total_bytes < 10 * 1024 * 1024) { // Send 10 MB of data
        ssize_t sent = send(sock, buffer, sizeof(buffer), 0);
        if (sent <= 0) {
            perror("⚠️ Uh-oh! Error while sending data");
            break;
        }
        total_bytes += sent;
    }
    gettimeofday(&end_time, NULL); // End timer

    // Display upload results
    double upload_time = calculate_time(start_time, end_time) / 1000.0; // Convert to seconds
    printf("🚀 Upload Test Completed!\n");
    printf("Total bytes sent: %ld bytes\n", total_bytes);
    printf("Upload Speed: %.2f Mbps\n", (total_bytes * 8.0) / (upload_time * 1e6));

    // Closing connection
    close(sock);
    printf("🔚 Connection Closed. Thank you for using the Speed Test Application! 🎉\n");
}

// Main function
int main() {
    test_speed();
    return 0;
}