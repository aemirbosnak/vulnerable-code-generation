//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/10MB.zip"
#define UPLOAD_URL "http://ipv4.upload.thinkbroadband.com/10MB.zip"
#define BUFFER_SIZE (10 * 1024 * 1024) // 10 MB buffer for download/upload

// Function to write data downloaded
size_t WriteCallback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb;
}

// Function to perform the download speed test
double performDownloadTest() {
    CURL *curl;
    CURLcode res;
    char *buffer = (char *)malloc(BUFFER_SIZE);
    
    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(EXIT_FAILURE);
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, buffer);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // we do not need the body for speed test

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "Download error: %s\n", curl_easy_strerror(res));
            free(buffer);
            curl_easy_cleanup(curl);
            return 0.0;
        }

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        double speed = (BUFFER_SIZE / time_taken) / (1024 * 1024); // speed in MB/s

        printf("Download Speed: %.2f MB/s\n", speed);

        free(buffer);
        curl_easy_cleanup(curl);
        return speed;
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }
}

// Function to perform the upload speed test
double performUploadTest() {
    CURL *curl;
    CURLcode res;
    char *buffer = (char *)malloc(BUFFER_SIZE);

    if (!buffer) {
        fprintf(stderr, "Failed to allocate memory for buffer\n");
        exit(EXIT_FAILURE);
    }

    memset(buffer, 'A', BUFFER_SIZE); // fill the buffer with data
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
        curl_easy_setopt(curl, CURLOPT_READDATA, buffer);
        curl_easy_setopt(curl, CURLOPT_INFILESIZE, BUFFER_SIZE);

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if (res != CURLE_OK) {
            fprintf(stderr, "Upload error: %s\n", curl_easy_strerror(res));
            free(buffer);
            curl_easy_cleanup(curl);
            return 0.0;
        }

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        double speed = (BUFFER_SIZE / time_taken) / (1024 * 1024); // speed in MB/s

        printf("Upload Speed: %.2f MB/s\n", speed);

        free(buffer);
        curl_easy_cleanup(curl);
        return speed;
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }
}

int main() {
    printf("Welcome to the Internet Speed Test!\n");
    printf("Testing download speed...\n");
    double downloadSpeed = performDownloadTest();
    
    printf("Testing upload speed...\n");
    double uploadSpeed = performUploadTest();

    printf("\nFinal Results:\n");
    printf("Download Speed: %.2f MB/s\n", downloadSpeed);
    printf("Upload Speed: %.2f MB/s\n", uploadSpeed);

    return 0;
}