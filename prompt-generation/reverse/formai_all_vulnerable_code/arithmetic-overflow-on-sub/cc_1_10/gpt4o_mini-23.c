//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <sys/time.h>

#define URL "http://speed.hetzner.de/100MB.bin" // Change to desired test URL
#define BUFFER_SIZE (1024 * 1024) // 1 MB buffer size for reading data

// Structure to hold download statistics
typedef struct {
    size_t size;
    size_t total_downloaded;
} DownloadData;

// Function to write data into our buffer
size_t write_callback(void *ptr, size_t size, size_t nmemb, DownloadData *data) {
    size_t total_size = size * nmemb;
    data->total_downloaded += total_size;
    return total_size;
}

// Function to measure download speed
double measure_download_speed() {
    CURL *curl;
    CURLcode res;
    DownloadData data;
    data.total_downloaded = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &data);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 30L);

        struct timeval start_time, end_time;
        gettimeofday(&start_time, NULL);

        res = curl_easy_perform(curl);

        gettimeofday(&end_time, NULL);

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1.0;
        }

        double time_diff = (end_time.tv_sec - start_time.tv_sec) + 
                           (end_time.tv_usec - start_time.tv_usec) / 1000000.0;

        // Calculate speed in Mbps
        double speed_mbps = (data.total_downloaded * 8.0) / (time_diff * 1000000); 

        curl_easy_cleanup(curl);
        return speed_mbps;
    }
    
    curl_global_cleanup();
    return -1.0;
}

int main() {
    printf("Starting Internet Speed Test...\n");
    double speed = measure_download_speed();

    if(speed >= 0) {
        printf("Download Speed: %.2f Mbps\n", speed);
    } else {
        printf("Failed to measure download speed.\n");
    }

    return 0;
}