//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define TEST_DATA_SIZE 1024 * 1024  // 1 MB
#define SERVER_ADDRESS "127.0.0.1"

void download_speed_test(int sock);
void upload_speed_test(int sock);

int main() {
    int sock;
    struct sockaddr_in server_addr;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Server address configuration
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection to the server failed");
        close(sock);
        return -1;
    }

    printf("Connected to the server. Starting Speed Test...\n");
    
    // Perform download speed test
    download_speed_test(sock);

    // Perform upload speed test
    upload_speed_test(sock);

    // Close the socket
    close(sock);

    return 0;
}

void download_speed_test(int sock) {
    char *buffer = (char *)malloc(TEST_DATA_SIZE);
    if (buffer == NULL) {
        perror("Memory allocation failed for download buffer");
        return;
    }
    
    // Fill buffer with dummy data
    memset(buffer, 'A', TEST_DATA_SIZE);
    
    printf("Starting Download Speed Test...\n");
    
    // Measure the time taken for the download
    clock_t start_time = clock();
    int received_bytes = 0;

    while (received_bytes < TEST_DATA_SIZE) {
        int bytes = recv(sock, buffer + received_bytes, TEST_DATA_SIZE - received_bytes, 0);
        if (bytes <= 0) {
            break;  // Break on error or connection closed
        }
        received_bytes += bytes;
    }

    clock_t end_time = clock();
    free(buffer);

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed = (received_bytes / 1024.0) / elapsed_time;  // Speed in KB/s
    printf("Downloaded %d bytes in %.2f seconds.\n", received_bytes, elapsed_time);
    printf("Download Speed: %.2f KB/s\n", speed);
}

void upload_speed_test(int sock) {
    char *buffer = (char *)malloc(TEST_DATA_SIZE);
    if (buffer == NULL) {
        perror("Memory allocation failed for upload buffer");
        return;
    }

    // Fill buffer with dummy data
    memset(buffer, 'B', TEST_DATA_SIZE);

    printf("Starting Upload Speed Test...\n");

    // Measure the time taken for the upload
    clock_t start_time = clock();
    int sent_bytes = 0;

    while (sent_bytes < TEST_DATA_SIZE) {
        int bytes = send(sock, buffer + sent_bytes, TEST_DATA_SIZE - sent_bytes, 0);
        if (bytes < 0) {
            perror("Error in sending data");
            break;  // Break on error
        }
        sent_bytes += bytes;
    }

    clock_t end_time = clock();
    free(buffer);

    // Calculate elapsed time in seconds
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    double speed = (sent_bytes / 1024.0) / elapsed_time;  // Speed in KB/s
    printf("Uploaded %d bytes in %.2f seconds.\n", sent_bytes, elapsed_time);
    printf("Upload Speed: %.2f KB/s\n", speed);
}