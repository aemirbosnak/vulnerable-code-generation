//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1" // Change to your speed test server IP
#define SERVER_PORT 8080
#define BUFFER_SIZE 1048576 // Size of data to send (1 MB)

// Function to measure time taken for a task
double measure_time(void (*task)(int), int param) {
    clock_t start = clock();
    task(param);
    clock_t end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Function to simulate download speed test
void download_speed_test(int data_size) {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer = malloc(data_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 'A', data_size); // Fill buffer with dummy data

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        free(buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        free(buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Measure sending time
    send(sock, buffer, data_size, 0);

    // Cleanup
    free(buffer);
    close(sock);
}

// Function to simulate upload speed test
void upload_speed_test(int data_size) {
    int sock;
    struct sockaddr_in server_addr;
    char *buffer = malloc(data_size);
    if (buffer == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }
    memset(buffer, 'B', data_size); // Fill buffer with dummy data
    
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address / Address not supported");
        free(buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        free(buffer);
        close(sock);
        exit(EXIT_FAILURE);
    }

    // Measure sending time
    send(sock, buffer, data_size, 0);

    // Cleanup
    free(buffer);
    close(sock);
}

// Function to calculate speed
void calculate_speed(double time_taken, int data_size) {
    double speed = (data_size / (1024.0 * 1024.0)) / time_taken; // Speed in MB/s
    printf("Speed: %.2f MB/s\n", speed);
}

// Main function
int main() {
    const int data_size = BUFFER_SIZE;

    printf("Starting Internet Speed Test...\n");

    // Download test
    printf("Download Test: Sending %d bytes...\n", data_size);
    double download_time = measure_time(download_speed_test, data_size);
    calculate_speed(download_time, data_size);

    // Upload test
    printf("Upload Test: Sending %d bytes...\n", data_size);
    double upload_time = measure_time(upload_speed_test, data_size);
    calculate_speed(upload_time, data_size);

    printf("Internet Speed Test completed successfully.\n");
    return 0;
}