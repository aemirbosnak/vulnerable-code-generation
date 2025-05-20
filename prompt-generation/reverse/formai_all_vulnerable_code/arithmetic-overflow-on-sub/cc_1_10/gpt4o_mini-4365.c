//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>

#define URL "http://speed.hetzner.de/100MB.bin" // You can change this URL to any file for speed testing.
#define SIZE 104857600 // Size of the file used for testing (100 MB).
#define BUFFER_SIZE 8192 // Size of the buffer for reading data.

void printColor(const char *text, const char *color) {
    printf("%s%s\033[0m", color, text); // Print the text in given color.
}

void printResult(double timeTaken, double speed, const char *operation) {
    printf("Operation: %s\n", operation);
    printf("Time taken: %.2f seconds\n", timeTaken);
    printf("Speed: %.2f MB/s\n", speed);
}

double measureDownloadSpeed() {
    struct timeval start, end;
    char command[256];
    sprintf(command, "curl -o /dev/null -s %s", URL); // Get the file silently without showing progress.

    gettimeofday(&start, NULL); // Start timing
    system(command); // Execute the command
    gettimeofday(&end, NULL); // End timing

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0; // Calculate elapsed time.
    return SIZE / (1024 * 1024) / elapsed; // Return speed in MB/s.
}

double measureUploadSpeed() {
    struct timeval start, end;
    char command[256];
    sprintf(command, "curl -T /dev/zero -o /dev/null -s http://your-upload-url.com/upload"); // Change this URL to your upload endpoint.

    gettimeofday(&start, NULL); // Start timing
    system(command); // Execute the command
    gettimeofday(&end, NULL); // End timing

    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0; // Calculate elapsed time.
    return SIZE / (1024 * 1024) / elapsed; // Return speed in MB/s.
}

int main() {
    double downloadSpeed, uploadSpeed;

    printColor("Welcome to the Internet Speed Test Application!\n", "\033[1;34m"); // Bold Blue Text
    printColor("Testing download speed...\n", "\033[1;32m"); // Bold Green Text

    downloadSpeed = measureDownloadSpeed(); // Measure download speed.

    printColor("Download Test Completed!\n", "\033[1;33m"); // Bold Yellow Text
    printResult(100.0 / downloadSpeed, downloadSpeed, "Download"); // Display results

    printColor("\nTesting upload speed...\n", "\033[1;32m"); // Bold Green Text

    uploadSpeed = measureUploadSpeed(); // Measure upload speed.

    printColor("Upload Test Completed!\n", "\033[1;33m"); // Bold Yellow Text
    printResult(100.0 / uploadSpeed, uploadSpeed, "Upload"); // Display results

    printColor("\nThank you for using the Internet Speed Test Application!\n", "\033[1;34m"); // Bold Blue Text

    return 0;
}