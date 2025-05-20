//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin"

// The structure for capturing response data
struct Memory {
    char *response;
    size_t size;
};

// Callback function to write data into the Memory structure
size_t write_callback(void *ptr, size_t size, size_t nmemb, struct Memory *mem) {
    size_t realsize = size * nmemb;
    mem->response = realloc(mem->response, mem->size + realsize + 1);
    if(mem->response == NULL) {
        printf("Not enough memory to allocate.\n");
        return 0;
    }
    memcpy(&(mem->response[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; 
    return realsize;
}

// Function to perform speed test
void perform_speed_test() {
    CURL *curl;
    CURLcode res;
    struct Memory chunk = { .response = malloc(1), .size = 0 };
    clock_t start, end;
    double cpu_time_used;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        // Measure the start time
        start = clock();
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // Measure the end time
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long downloaded_size;
            curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD, &downloaded_size);
            double speed_mbps = (downloaded_size / 1024.0 / 1024.0) / cpu_time_used;
            printf("Download size: %ld bytes\n", downloaded_size);
            printf("Time taken: %f seconds\n", cpu_time_used);
            printf("Speed: %.2f Mbps\n", speed_mbps);
        }
        
        // Free the Memory structure
        free(chunk.response);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

int main() {
    printf("======================================\n");
    printf("    Internet Speed Test Application   \n");
    printf("======================================\n");
    
    perform_speed_test();
    
    printf("======================================\n");
    return 0;
}