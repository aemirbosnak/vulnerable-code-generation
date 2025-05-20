//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TEST_DURATION 5 // Duration for each test in seconds
#define FILE_SIZE (1 * 1024 * 1024) // Size of the file to be created for upload in bytes
#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/5MB.zip" // Test file for download

void download_file(const char *url, const char *output_filename);
void upload_file(const char *filename);
double measure_speed(int bytes_transferred, double duration);

int main() {
    char tmp_upload_file[] = "testfile.tmp"; // temporary upload file
    char command[256];

    // Create a temporary file for upload test
    FILE *upload_fp = fopen(tmp_upload_file, "wb");
    if (upload_fp == NULL) {
        perror("Failed to create temporary file for upload test");
        return EXIT_FAILURE;
    }

    // Fill the temporary file with random data
    char *data = malloc(FILE_SIZE);
    if (data == NULL) {
        perror("Failed to allocate memory for upload test data");
        fclose(upload_fp);
        return EXIT_FAILURE;
    }
    memset(data, 'A', FILE_SIZE); // Fill with 'A's
    fwrite(data, sizeof(char), FILE_SIZE, upload_fp);
    fclose(upload_fp);
    free(data);

    // Measure download speed
    printf("Starting download speed test...\n");
    download_file(DOWNLOAD_URL, "downloaded_file.tmp");

    // Measure upload speed
    printf("Starting upload speed test...\n");
    upload_file(tmp_upload_file);

    // Clean up
    remove(tmp_upload_file);
    remove("downloaded_file.tmp");

    return EXIT_SUCCESS;
}

void download_file(const char *url, const char *output_filename) {
    char command[512];
    snprintf(command, sizeof(command), "curl -o %s -w '%%{size_download}' -s %s", output_filename, url);

    clock_t start_time = clock();
    int bytes_downloaded = system(command); // Execute curl command
    clock_t end_time = clock();

    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (bytes_downloaded != 0) {
        fprintf(stderr, "Download failed\n");
        return;
    }

    double speed = measure_speed(bytes_downloaded, duration);
    printf("Download completed: %d bytes in %.2f seconds (%.2f Mbps)\n",
           bytes_downloaded, duration, speed);
}

void upload_file(const char *filename) {
    char command[512];
    snprintf(command, sizeof(command), "curl -T %s -w '%%{size_upload}' -s http://example.com/upload", filename);

    clock_t start_time = clock();
    int bytes_uploaded = system(command);
    clock_t end_time = clock();

    double duration = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    if (bytes_uploaded != 0) {
        fprintf(stderr, "Upload failed\n");
        return;
    }

    double speed = measure_speed(bytes_uploaded, duration);
    printf("Upload completed: %d bytes in %.2f seconds (%.2f Mbps)\n",
           bytes_uploaded, duration, speed);
}

double measure_speed(int bytes_transferred, double duration) {
    if (duration <= 0) {
        return 0.0;
    }
    return (bytes_transferred * 8.0) / (duration * 1e6); // Convert bytes to megabits
}