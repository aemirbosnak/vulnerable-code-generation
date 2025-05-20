//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define TEST_FILE_SIZE (50 * 1024 * 1024) // 50 MB
#define URL "http://ipv4.download.thinkbroadband.com/5MB.zip"

// Callback function for writing the data received in a download
size_t write_callback(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

// Function to perform download speed test
double download_speed_test() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    double speed;
    clock_t start, end;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen("testfile.bin", "wb");
        if (fp == NULL) {
            fprintf(stderr, "Failed to create file for download test\n");
            return -1;
        }

        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        start = clock();
        res = curl_easy_perform(curl);
        end = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            fclose(fp);
            return -1;
        }

        fclose(fp);
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Download speed: %.2f MB/s\n", (TEST_FILE_SIZE / (1024.0 * 1024.0)) / time_taken);

        curl_easy_cleanup(curl);
        return speed;
    }
    return -1;
}

// Function to perform upload speed test
double upload_speed_test() {
    CURL *curl;
    CURLcode res;
    double speed;
    clock_t start, end;

    char *data = malloc(TEST_FILE_SIZE);
    memset(data, 'A', TEST_FILE_SIZE); // Fill the data with 'A'
    
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, TEST_FILE_SIZE);

        start = clock();
        res = curl_easy_perform(curl);
        end = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(data);
            return -1;
        }

        curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &speed);

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Upload speed: %.2f MB/s\n", (TEST_FILE_SIZE / (1024.0 * 1024.0)) / time_taken);

        free(data);
        curl_easy_cleanup(curl);
        return speed;
    }
    free(data);
    return -1;
}

int main(void) {
    printf("Starting Internet Speed Test...\n");
    
    double download_speed = download_speed_test();
    if (download_speed < 0) {
        fprintf(stderr, "Download speed test failed.\n");
    }

    double upload_speed = upload_speed_test();
    if (upload_speed < 0) {
        fprintf(stderr, "Upload speed test failed.\n");
    }

    printf("Speed test completed!\n");
    return 0;
}