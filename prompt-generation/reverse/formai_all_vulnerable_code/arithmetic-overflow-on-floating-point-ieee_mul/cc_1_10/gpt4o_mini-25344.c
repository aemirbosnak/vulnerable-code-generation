//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define DOWNLOAD_URL "http://speed.hetzner.de/100MB.bin" // URL for download speed test
#define UPLOAD_URL "https://httpbin.org/post" // URL for upload speed test
#define DATA "Test data for speed upload" // Data to upload for speed test

// Callback function for writing the data received on download
size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // Ignore data
}

// Function to perform the download speed test
double test_download_speed() {
    CURL *curl;
    CURLcode res;
    double speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);

        res = curl_easy_perform(curl);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Download speed test failed: %s\n", curl_easy_strerror(res));
            return 0.0;
        }
        
        curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return speed; // Speed in bytes/second
}

// Function to perform the upload speed test
double test_upload_speed() {
    CURL *curl;
    CURLcode res;
    double speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, DATA);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
        
        // We will measure the upload speed here
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        
        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            fprintf(stderr, "Upload speed test failed: %s\n", curl_easy_strerror(res));
            return 0.0;
        }

        curl_easy_getinfo(curl, CURLINFO_SPEED_UPLOAD, &speed);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return speed; // Speed in bytes/second
}

int main() {
    printf("=== Internet Speed Test ===\n");
    
    // Test download speed
    double download_speed = test_download_speed();
    if (download_speed > 0) {
        printf("Download Speed: %.2f Mbps\n", (download_speed * 8) / (1024 * 1024)); // Convert to Mbps
    }

    // Test upload speed
    double upload_speed = test_upload_speed();
    if (upload_speed > 0) {
        printf("Upload Speed: %.2f Mbps\n", (upload_speed * 8) / (1024 * 1024)); // Convert to Mbps
    }

    printf("===========================\n");
    return 0;
}