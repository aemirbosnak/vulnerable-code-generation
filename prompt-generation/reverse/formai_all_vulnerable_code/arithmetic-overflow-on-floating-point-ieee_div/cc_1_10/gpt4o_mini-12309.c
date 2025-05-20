//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define URL "http://example.com" // Replace with a target URL for speed test

void delay(int seconds) {
    sleep(seconds);
}

double get_time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1e6 + (end.tv_usec - start.tv_usec);
}

void perform_speed_test() {
    struct timeval start, end;
    FILE *fp;
    char command[256];
    long data_size = 0;

    snprintf(command, sizeof(command), "curl -s -o /dev/null -w '%%{size_download}' %s", URL);

    gettimeofday(&start, NULL);
    fp = popen(command, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    fscanf(fp, "%ld", &data_size);
    pclose(fp);
    gettimeofday(&end, NULL);

    double duration = get_time_diff(start, end) / 1e6; // Convert to seconds
    double speed_mbps = (data_size * 8) / (duration * 1e6); // Convert to Mbps

    printf("Downloaded %ld bytes in %.2f seconds.\n", data_size, duration);
    printf("Speed: %.2f Mbps\n", speed_mbps);
}

int main() {
    printf("=== Simple Internet Speed Test ===\n");
    printf("Testing download speed...\n");

    // Proceed with the speed test
    perform_speed_test();

    printf("Test completed. Thank you for using our speed test.\n");

    // Extra delay before exiting
    printf("Exiting in 3 seconds...\n");
    delay(3);
    
    return 0;
}