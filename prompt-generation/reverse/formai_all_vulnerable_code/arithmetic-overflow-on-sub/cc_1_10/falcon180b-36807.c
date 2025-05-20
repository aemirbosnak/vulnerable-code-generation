//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAX_SAMPLES 100
#define SAMPLE_INTERVAL 1000 // In milliseconds
#define SAMPLE_SIZE 1024 // In bytes

int main() {
    char hostname[256];
    double download_speed, upload_speed;
    int i, sample_count = 0, total_download_bytes = 0, total_upload_bytes = 0;
    struct timespec start_time, end_time;

    gethostname(hostname, sizeof(hostname));

    printf("Starting internet speed test for %s...\n", hostname);
    fflush(stdout);

    clock_gettime(CLOCK_REALTIME, &start_time);

    while (sample_count < MAX_SAMPLES) {
        if (sample_count == 0) {
            printf("Downloading test file...\n");
            fflush(stdout);
        }

        if (sample_count % 2 == 0) {
            total_download_bytes += SAMPLE_SIZE;
        } else {
            total_upload_bytes += SAMPLE_SIZE;
        }

        clock_gettime(CLOCK_REALTIME, &end_time);
        double elapsed_time = (end_time.tv_sec - start_time.tv_sec) +
                             (end_time.tv_nsec - start_time.tv_nsec) * 1e-9;

        if (elapsed_time >= SAMPLE_INTERVAL) {
            double current_download_speed = (double)total_download_bytes / elapsed_time;
            double current_upload_speed = (double)total_upload_bytes / elapsed_time;

            if (sample_count == 0) {
                download_speed = current_download_speed;
                upload_speed = current_upload_speed;
            } else {
                download_speed = (download_speed + current_download_speed) / 2;
                upload_speed = (upload_speed + current_upload_speed) / 2;
            }

            total_download_bytes = 0;
            total_upload_bytes = 0;
            sample_count++;
        }

        usleep(SAMPLE_INTERVAL * 1000);
    }

    printf("Internet speed test complete for %s.\n", hostname);
    printf("Download speed: %.2f Mbps\n", download_speed / (1024 * 1024));
    printf("Upload speed: %.2f Mbps\n", upload_speed / (1024 * 1024));

    return 0;
}