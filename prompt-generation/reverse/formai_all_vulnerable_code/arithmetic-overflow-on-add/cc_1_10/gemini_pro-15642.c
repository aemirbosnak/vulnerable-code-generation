//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_BUFFER_SIZE 1024

// Function to get the current time in milliseconds
long long get_current_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (long long)ts.tv_sec * 1000LL + (long long)ts.tv_nsec / 1000000LL;
}

// Function to download a file from a URL
int download_file(char *url, char *filename) {
    // Open the URL
    FILE *fp = fopen(url, "rb");
    if (fp == NULL) {
        return -1;
    }

    // Create a file to store the downloaded data
    FILE *fp_out = fopen(filename, "wb");
    if (fp_out == NULL) {
        fclose(fp);
        return -1;
    }

    // Read the data from the URL and write it to the file
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, fp)) > 0) {
        fwrite(buffer, 1, bytes_read, fp_out);
    }

    // Close the files
    fclose(fp);
    fclose(fp_out);

    return 0;
}

// Function to calculate the download speed
double calculate_download_speed(char *filename, long long start_time, long long end_time) {
    // Get the file size
    long long file_size = 0;
    FILE *fp = fopen(filename, "rb");
    if (fp != NULL) {
        fseek(fp, 0, SEEK_END);
        file_size = ftell(fp);
        fclose(fp);
    }

    // Calculate the download speed
    double download_speed = (double)file_size / (end_time - start_time) * 1000.0; // Convert to KB/s

    return download_speed;
}

int main(int argc, char **argv) {
    // Check if the user has provided a URL
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        return -1;
    }

    // Get the URL from the command line
    char *url = argv[1];

    // Create a filename for the downloaded file
    char filename[MAX_URL_LENGTH];
    strcpy(filename, url);
    char *p = filename;
    while (*p != '\0') {
        if (*p == '/') {
            *p = '_';
        }
        p++;
    }

    // Start the timer
    long long start_time = get_current_time_ms();

    // Download the file
    int download_result = download_file(url, filename);
    if (download_result != 0) {
        printf("Error downloading file: %s\n", url);
        return -1;
    }

    // Stop the timer
    long long end_time = get_current_time_ms();

    // Calculate the download speed
    double download_speed = calculate_download_speed(filename, start_time, end_time);

    // Print the download speed
    printf("Download speed: %.2f KB/s\n", download_speed);

    // Delete the downloaded file
    remove(filename);

    return 0;
}