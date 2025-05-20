//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>
#include <time.h>

#define URL "http://ipv4.download.thinkbroadband.com/10MB.zip" // URL for speed test download
#define UPLOAD_URL "https://httpbin.org/post" // URL for speed test upload
#define BUFFER_SIZE 1000

// Callback function for writing the downloaded data
size_t write_data(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // We don't need the data, just return the size to ignore
}

// Function to test download speed
void test_download_speed() {
    CURL *curl;
    CURLcode res;
    double speed;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_NOBODY, 1L); // We don't need to download the body
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set a timeout for the request

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        // Calculate the time taken
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
            printf("Download Speed: %.2f Mbps\n", (speed * 8) / 1024 / 1024);
            printf("Time taken for download: %.2f seconds\n", time_taken);
        } else {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Function to test upload speed
void test_upload_speed() {
    CURL *curl;
    CURLcode res;
    char data[BUFFER_SIZE];
    double speed;

    // Create a simple data packet to upload
    memset(data, 'A', BUFFER_SIZE - 1);
    data[BUFFER_SIZE - 1] = '\0'; // Null-terminate for safety

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)BUFFER_SIZE);
        
        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        // Calculate the time taken
        double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if(res == CURLE_OK) {
            curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &speed);
            printf("Upload Speed: %.2f Mbps\n", (speed * 8) / 1024 / 1024);
            printf("Time taken for upload: %.2f seconds\n", time_taken);
        } else {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

// Entry point of the program
int main() {
    printf("Internet Speed Test Application\n");
    printf("Starting download speed test...\n");
    test_download_speed();
    printf("\nStarting upload speed test...\n");
    test_upload_speed();
    return 0;
}