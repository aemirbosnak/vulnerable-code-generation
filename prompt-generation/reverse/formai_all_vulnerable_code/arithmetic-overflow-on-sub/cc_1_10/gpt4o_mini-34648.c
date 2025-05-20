//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>

#define TEST_URL "http://speed.hetzner.de/100MB.bin" // Replace with a high bandwidth testing URL
#define TEST_FILE "testfile.bin"
#define DATA_SIZE (100 * 1024 * 1024) // 100 MB

// Function to execute a shell command and return the time taken
double exec_command(const char *command) {
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    int result = system(command);
    
    gettimeofday(&end, NULL);
    if (result != 0) {
        fprintf(stderr, "Command failed: %s\n", command);
        return -1;
    }

    double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    return time_taken;
}

// Function to calculate speed in Mbps
double calculate_speed(double time_taken, size_t data_size) {
    return (data_size * 8) / (time_taken * 1000000); // Mbps
}

// Function to clean up test file
void cleanup(const char *filename) {
    if (remove(filename) != 0) {
        fprintf(stderr, "Error deleting file: %s\n", filename);
    }
}

int main() {
    printf("Welcome to the Simple Internet Speed Test Application!\n");

    // Download Speed Test
    printf("Testing download speed...\n");
    char download_command[256];
    snprintf(download_command, sizeof(download_command), "curl -o %s --limit-rate 10M %s", TEST_FILE, TEST_URL);
    
    double download_time = exec_command(download_command);
    
    if (download_time < 0) {
        return EXIT_FAILURE;
    }
    
    double download_speed = calculate_speed(download_time, DATA_SIZE);
    printf("Download Speed: %.2f Mbps\n", download_speed);
    
    // Upload Speed Test
    printf("Testing upload speed...\n");
    char upload_command[256];
    snprintf(upload_command, sizeof(upload_command), "curl -T %s http://your-upload-server.com/upload", TEST_FILE);
    
    double upload_time = exec_command(upload_command);
    
    if (upload_time < 0) {
        cleanup(TEST_FILE);
        return EXIT_FAILURE;
    }

    double upload_speed = calculate_speed(upload_time, DATA_SIZE);
    printf("Upload Speed: %.2f Mbps\n", upload_speed);

    // Clean up generated file
    cleanup(TEST_FILE);
    
    printf("Speed test completed successfully!\n");
    return EXIT_SUCCESS;
}