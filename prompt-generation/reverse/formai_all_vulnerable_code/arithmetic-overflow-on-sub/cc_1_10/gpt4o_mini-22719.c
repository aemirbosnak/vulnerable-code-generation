//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 8192

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    long *fetchedBytes = (long *)userdata;
    *fetchedBytes += size * nmemb;
    return size * nmemb;
}

double measure_download_speed(const char *url, long *bytes_downloaded) {
    CURL *curl;
    CURLcode res;

    *bytes_downloaded = 0;
    double elapsed_time;
    curl = curl_easy_init();
    if (curl) {
        struct timespec start, end;

        clock_gettime(CLOCK_MONOTONIC, &start);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)bytes_downloaded);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1.0;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

        curl_easy_cleanup(curl);
        return (double)(*bytes_downloaded) / (elapsed_time * 1024.0); // KB/s
    }
    return -1.0;
}

double measure_upload_speed(const char *url, long *bytes_uploaded) {
    CURL *curl;
    CURLcode res;

    *bytes_uploaded = 0;
    double elapsed_time;
    curl = curl_easy_init();
    if (curl) {
        struct timespec start, end;
        const char *data = "This is a test upload for speed measurement.";
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        clock_gettime(CLOCK_MONOTONIC, &start);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)bytes_uploaded);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 0L);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            curl_easy_cleanup(curl);
            return -1.0;
        }

        clock_gettime(CLOCK_MONOTONIC, &end);
        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;

        curl_easy_cleanup(curl);
        return (double)(*bytes_uploaded) / (elapsed_time * 1024.0); // KB/s
    }
    return -1.0;
}

int main(void) {
    const char *download_test_url = "http://speed.hetzner.de/100MB.bin"; // Example download URL
    const char *upload_test_url = "http://your-upload-server.com/upload"; // Example upload URL

    long bytes_downloaded, bytes_uploaded;
    double download_speed, upload_speed;

    printf("Starting Internet Speed Test...\n\n");

    printf("Testing Download Speed...\n");
    download_speed = measure_download_speed(download_test_url, &bytes_downloaded);
    if (download_speed < 0) {
        printf("Failed to measure download speed.\n");
    } else {
        printf("Downloaded %ld bytes at a speed of %.2f KB/s\n", bytes_downloaded, download_speed);
    }

    printf("\nTesting Upload Speed...\n");
    upload_speed = measure_upload_speed(upload_test_url, &bytes_uploaded);
    if (upload_speed < 0) {
        printf("Failed to measure upload speed.\n");
    } else {
        printf("Uploaded %ld bytes at a speed of %.2f KB/s\n", bytes_uploaded, upload_speed);
    }

    printf("\nSpeed Test Completed!\n");
    return 0;
}