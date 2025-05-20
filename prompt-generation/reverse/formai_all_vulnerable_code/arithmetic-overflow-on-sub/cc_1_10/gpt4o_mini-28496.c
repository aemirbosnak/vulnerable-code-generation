//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define DOWNLOAD_URL "http://ipv4.download.thinkbroadband.com/5MB.zip"
#define UPLOAD_URL "http://httpbin.org/post"
#define BUFFER_SIZE 1024 * 1024 // 1 MB buffer for download

size_t write_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // We just discard the content
}

double measure_download_speed() {
    CURL *curl;
    CURLcode res;
    double speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
        
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
            speed = 0.0;
        } else {
            double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            speed = (BUFFER_SIZE / 1024.0) / elapsed_time; // Speed in KB/s
        }
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return speed;
}

double measure_upload_speed() {
    CURL *curl;
    CURLcode res;
    double speed;
    char data[BUFFER_SIZE];
    memset(data, 'a', sizeof(data)); // Fill with dummy data

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)sizeof(data));
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);

        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        
        if(res != CURLE_OK) {
            fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
            speed = 0.0;
        } else {
            double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            speed = (BUFFER_SIZE / 1024.0) / elapsed_time; // Speed in KB/s
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return speed;
}

int main() {
    printf("Internet Speed Test\n");
    printf("====================\n");

    printf("Measuring download speed...\n");
    double download_speed = measure_download_speed();
    if (download_speed > 0) {
        printf("Download Speed: %.2f KB/s\n", download_speed);
    }
    
    printf("Measuring upload speed...\n");
    double upload_speed = measure_upload_speed();
    if (upload_speed > 0) {
        printf("Upload Speed: %.2f KB/s\n", upload_speed);
    }

    return 0;
}