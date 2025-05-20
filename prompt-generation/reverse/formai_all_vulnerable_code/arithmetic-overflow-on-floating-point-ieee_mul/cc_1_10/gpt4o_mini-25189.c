//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE (1024 * 1024) // 1 MB buffer for speed test data
#define TEST_URL "http://ipv4.download.thinkbroadband.com/1MB.zip" // URL to test download speed

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // Simply ignore the data received
}

void testDownloadSpeed() {
    CURL *curl;
    CURLcode res;
    double speed;
    struct timespec start, end;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        // Setup the URL and callback
        curl_easy_setopt(curl, CURLOPT_URL, TEST_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        // Start timing
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Perform the download
        res = curl_easy_perform(curl);

        // End timing
        clock_gettime(CLOCK_MONOTONIC, &end);

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);

            long elapsed_nsec = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
            double elapsed_sec = elapsed_nsec / 1e9;

            printf("Download Speed: %.2f Mbps (Downloaded 1MB in %.2f seconds)\n", 
                   (speed * 8) / (1024 * 1024), elapsed_sec);
        } else {
            fprintf(stderr, "Download speed test failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
}

void testUploadSpeed() {
    CURL *curl;
    CURLcode res;
    double speed;
    struct timespec start, end;
    char *data = malloc(BUFFER_SIZE);
    
    if (!data) {
        fprintf(stderr, "Memory allocation for upload data failed\n");
        return;
    }

    // Initialize buffer with random data
    for (size_t i = 0; i < BUFFER_SIZE; i++) {
        data[i] = rand() % 256;
    }

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "http://example.com/upload"); // Replace with actual upload URL
        curl_easy_setopt(curl, CURLOPT_POST, 1L);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, BUFFER_SIZE);
        
        // Start timing
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        // Perform the upload
        res = curl_easy_perform(curl);
        
        // End timing
        clock_gettime(CLOCK_MONOTONIC, &end);
        
        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &speed);

            long elapsed_nsec = (end.tv_sec - start.tv_sec) * 1e9 + (end.tv_nsec - start.tv_nsec);
            double elapsed_sec = elapsed_nsec / 1e9;

            printf("Upload Speed: %.2f Mbps (Uploaded 1MB in %.2f seconds)\n", 
                   (speed * 8) / (1024 * 1024), elapsed_sec);
        } else {
            fprintf(stderr, "Upload speed test failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
    free(data);
}

int main() {
    printf("---- Internet Speed Test Application ----\n");
    printf("Testing Download Speed...\n");
    testDownloadSpeed();

    printf("\nTesting Upload Speed...\n");
    testUploadSpeed();

    return 0;
}