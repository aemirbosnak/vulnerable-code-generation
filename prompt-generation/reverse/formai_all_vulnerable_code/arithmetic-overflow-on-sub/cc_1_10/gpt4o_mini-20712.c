//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin"

typedef struct {
    size_t total_size;
    double total_time;
} DownloadInfo;

// Progress callback to store information about the transfer
static int progress_callback(void *ptr, curl_off_t total_to_download,
                             curl_off_t now_downloaded, curl_off_t total_to_upload,
                             curl_off_t now_uploaded) {
    DownloadInfo *info = (DownloadInfo *)ptr;
    info->total_size = total_to_download;
    return 0; // Return 0 to continue the transfer.
}

// Write callback that discards the downloaded data
static size_t discard_callback(void *ptr, size_t size, size_t nmemb, void *userdata) {
    return size * nmemb; // We don't need the data, just return it
}

int main() {
    CURL *curl;
    CURLcode res;

    DownloadInfo info = {0, 0};

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, discard_callback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, progress_callback);
        curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &info);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); // Enable progress meter

        // Start clock to measure the time taken for download
        clock_t start_time = clock();
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        
        // End clock
        clock_t end_time = clock();
        info.total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double speed = (info.total_size / 1024.0) / info.total_time; // Speed in KB/s
            printf("Download Speed: %.2f KB/s\n", speed);
            printf("Total Size: %zu bytes\n", info.total_size);
            printf("Total Time: %.2f seconds\n", info.total_time);
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize curl.\n");
    }

    curl_global_cleanup();
    return 0;
}