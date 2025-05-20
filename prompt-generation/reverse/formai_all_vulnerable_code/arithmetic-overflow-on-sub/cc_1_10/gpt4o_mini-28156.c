//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define DOWNLOAD_URL "http://speed.hetzner.de/100MB.bin"
#define UPLOAD_URL "http://example.com/upload" // Replace with an actual upload endpoint

struct Memory {
    char *response;
    size_t size;
};

size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct Memory *mem) {
    size_t realsize = size * nmemb;
    mem->response = realloc(mem->response, mem->size + realsize + 1);
    if(mem->response == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0; // Out of memory
    }
    memcpy(&(mem->response[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;
    return realsize;
}

double measure_download_speed(CURL *curl) {
    curl_easy_setopt(curl, CURLOPT_URL, DOWNLOAD_URL);
    struct Memory chunk = {0};
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // Disable progress meter

    clock_t start = clock();
    CURLcode res = curl_easy_perform(curl);
    clock_t end = clock();

    if(res != CURLE_OK) {
        fprintf(stderr, "Download failed: %s\n", curl_easy_strerror(res));
        return -1;
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Time in seconds
    double speed_mbps = (chunk.size * 8) / (1024 * 1024) / time_taken; // Speed in Mbps
    free(chunk.response);
    return speed_mbps;
}

double measure_upload_speed(CURL *curl) {
    const char *data = "This is a test upload data.";
    curl_easy_setopt(curl, CURLOPT_URL, UPLOAD_URL);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(data));
    
    clock_t start = clock();
    CURLcode res = curl_easy_perform(curl);
    clock_t end = clock();

    if(res != CURLE_OK) {
        fprintf(stderr, "Upload failed: %s\n", curl_easy_strerror(res));
        return -1;
    }

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; // Time in seconds
    double speed_mbps = (strlen(data) * 8) / (1024 * 1024) / time_taken; // Speed in Mbps
    return speed_mbps;
}

int main() {
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        double download_speed = measure_download_speed(curl);
        if(download_speed != -1) {
            printf("Download Speed: %.2f Mbps\n", download_speed);
        }

        double upload_speed = measure_upload_speed(curl);
        if(upload_speed != -1) {
            printf("Upload Speed: %.2f Mbps\n", upload_speed);
        }
        
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }

    curl_global_cleanup();
    return 0;
}