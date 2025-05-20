//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define TEST_URL "http://ipv4.download.thinkbroadband.com/1MB.zip" // Size: 1MB

// Function prototypes
void downloadFile(const char *url);
float calculateSpeed(struct timeval start, struct timeval end, long bytes);
void downloadAndMeasure(const char *url);

int main() {
    printf("====================================\n");
    printf("    Internet Speed Test Application  \n");
    printf("====================================\n");
    printf("Testing download speed...\n");
    downloadAndMeasure(TEST_URL);
    return 0;
}

void downloadFile(const char *url) {
    char command[256];
    snprintf(command, sizeof(command), "curl -s -w '%%{size_download}\n' -o /dev/null %s", url);
    system(command);
}

float calculateSpeed(struct timeval start, struct timeval end, long bytes) {
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    float elapsedTime = seconds + microseconds / 1000000.0;
    return (bytes * 8) / (elapsedTime * 1024); // Speed in Kbps
}

void downloadAndMeasure(const char *url) {
    struct timeval start, end;
    long downloadedBytes = 0;

    gettimeofday(&start, NULL); // Start measuring time

    // Download the file and capture the size
    FILE *fp = popen("curl -s -o /dev/null -w '%{size_download}' 'http://ipv4.download.thinkbroadband.com/1MB.zip'", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run curl command\n");
        exit(1);
    }

    // Read the output from the command
    char buffer[BUFFER_SIZE];
    if (fgets(buffer, sizeof(buffer), fp) != NULL) {
        downloadedBytes = strtol(buffer, NULL, 10);
    }
    pclose(fp);

    gettimeofday(&end, NULL); // End measuring time

    // Calculate speed
    float speed = calculateSpeed(start, end, downloadedBytes);
    printf("Download Speed: %.2f Kbps\n", speed);
}