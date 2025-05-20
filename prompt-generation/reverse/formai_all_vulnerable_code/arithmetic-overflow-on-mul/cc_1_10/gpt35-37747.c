//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define URL "http://example.com/file.bin" // The file used for measuring the download speed
#define MAX_BUFFER_SIZE (1024 * 1024) // Maximum buffer size for downloaded data

/* Returns the current time in milliseconds */
unsigned long long current_time() {
    struct timespec tp;
    clock_gettime(CLOCK_REALTIME, &tp);
    return tp.tv_sec * 1000 + tp.tv_nsec / 1000000;
}

/* Downloads a file from the specified URL and measures the time it took to download it */
unsigned long long measure_download_speed() {
    FILE *fp = fopen("/dev/null", "w"); // Open a null device to discard the downloaded data
    if (!fp) {
        perror("fopen");
        return 0;
    }

    unsigned char *buffer = malloc(MAX_BUFFER_SIZE);
    if (!buffer) {
        perror("malloc");
        fclose(fp);
        return 0;
    }

    unsigned long long start_time = current_time();

    FILE *curl = popen("curl -s " URL, "r"); // Download the file with curl
    if (!curl) {
        perror("popen");
        free(buffer);
        fclose(fp);
        return 0;
    }

    size_t bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, curl);
    while (bytes_read > 0) { // Discard downloaded data
        fwrite(buffer, 1, bytes_read, fp);
        bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, curl);
    }

    fclose(curl);
    free(buffer);
    fclose(fp);

    return current_time() - start_time;
}

int main() {
    printf("Measuring download speed...\n");

    unsigned long long download_speed = measure_download_speed();
    double download_speed_mbps = (double) MAX_BUFFER_SIZE * 8 / download_speed / 1e3 * 1e3;
    printf("Download speed: %.2lf Mbps\n", download_speed_mbps);

    return 0;
}