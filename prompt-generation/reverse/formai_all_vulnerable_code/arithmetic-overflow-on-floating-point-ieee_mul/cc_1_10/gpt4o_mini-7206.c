//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define URL_DOWNLOAD "http://ipv4.download.thinkbroadband.com/10MB.zip" // Test file for download
#define URL_UPLOAD   "https://httpbin.org/post" // Test endpoint for upload
#define FILE_SIZE    10485760 // 10MB in bytes

void calculate_speed(long bytes, double time_taken) {
    double speed_mbps = (bytes * 8) / (1024.0 * 1024.0 * time_taken);
    printf("Speed: %.2f Mbps\n", speed_mbps);
}

void test_download() {
    printf("Testing download speed...\n");
    char command[256];
    snprintf(command, sizeof(command), "wget -O /dev/null %s", URL_DOWNLOAD);

    time_t start_time = time(NULL);
    int result = system(command);
    time_t end_time = time(NULL);

    if (result == 0) {
        double time_taken = difftime(end_time, start_time);
        printf("Download test completed successfully.\n");
        calculate_speed(FILE_SIZE, time_taken);
    } else {
        printf("Download test failed.\n");
    }
}

void test_upload() {
    printf("Testing upload speed...\n");
    char command[256];
    
    // Create a temporary file with 10MB of random data to upload
    FILE *fp = fopen("tempfile", "wb");
    if (fp == NULL) {
        perror("File creation failed");
        return;
    }
    
    // Fill the file with random data
    for (long i = 0; i < FILE_SIZE; i++) {
        fputc(rand() % 256, fp);
    }
    fclose(fp);

    time_t start_time = time(NULL);
    snprintf(command, sizeof(command), "curl -X POST -F 'file=@tempfile' %s", URL_UPLOAD);
    int result = system(command);
    time_t end_time = time(NULL);

    if (result == 0) {
        double time_taken = difftime(end_time, start_time);
        printf("Upload test completed successfully.\n");
        calculate_speed(FILE_SIZE, time_taken);
    } else {
        printf("Upload test failed.\n");
    }

    // Remove temporary file
    remove("tempfile");
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Executing tests, please wait...\n");
    
    // Seed random number generator
    srand(time(NULL));

    test_download();
    test_upload();

    printf("Test completed. Thank you for using this geometric marvel of technology! \n");
    
    return 0;
}