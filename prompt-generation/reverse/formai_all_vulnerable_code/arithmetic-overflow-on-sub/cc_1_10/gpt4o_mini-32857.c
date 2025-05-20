//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://ipv4.download.thinkbroadband.com/100MB.zip"
#define BUFFER_SIZE 1024 * 1024 // 1 MB

typedef struct {
    char *data;
    size_t size;
} MemoryBlock;

size_t write_callback(void *ptr, size_t size, size_t nmemb, MemoryBlock *data) {
    size_t total_size = size * nmemb;
    data->data = realloc(data->data, data->size + total_size + 1);
    if (data->data == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(data->data[data->size]), ptr, total_size);
    data->size += total_size;
    data->data[data->size] = 0;
    return total_size;
}

void calculate_download_speed(double duration, long total_bytes) {
    double speed_mbps = (total_bytes * 8.0) / (duration * 1e6); // Convert to Mbps
    printf("Download Speed: %.2f Mbps\n", speed_mbps);
}

void calculate_upload_speed(double duration, long total_bytes) {
    double speed_mbps = (total_bytes * 8.0) / (duration * 1e6); // Convert to Mbps
    printf("Upload Speed: %.2f Mbps\n", speed_mbps);
}

void perform_download_test() {
    CURL *curl;
    CURLcode res;
    MemoryBlock chunk;
    chunk.data = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        clock_t start_time, end_time;
        double total_time;

        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        start_time = clock();
        res = curl_easy_perform(curl);
        end_time = clock();
        total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            calculate_download_speed(total_time, chunk.size);
        }

        free(chunk.data);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void perform_upload_test() {
    CURL *curl;
    CURLcode res;
    MemoryBlock chunk;
    chunk.data = malloc(BUFFER_SIZE);
    memset(chunk.data, 'x', BUFFER_SIZE); // Simulating 1 MB of data
    chunk.size = BUFFER_SIZE;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if (curl) {
        clock_t start_time, end_time;
        double total_time;

        curl_easy_setopt(curl, CURLOPT_URL, "http://httpbin.org/post");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, chunk.data);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, chunk.size);
        
        start_time = clock();
        res = curl_easy_perform(curl);
        end_time = clock();
        total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            calculate_upload_speed(total_time, chunk.size);
        }

        free(chunk.data);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main() {
    printf("=== Internet Speed Test ===\n");
    
    printf("Performing Download Test...\n");
    perform_download_test();
    printf("Performing Upload Test...\n");
    perform_upload_test();
    
    return 0;
}