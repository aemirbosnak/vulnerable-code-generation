//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define TEST_URL "http://ipv4.download.thinkbroadband.com/5MB.zip"
#define BUFFER_SIZE (1024 * 1024) // Read in 1MB chunks

// This structure holds the data for writing
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if(userp->memory == NULL) return 0; // Out of memory!
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate the string
    return realsize;
}

// Function to perform the speed test
void perform_speed_test() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk = {NULL, 0};
    double time_taken;
    long response_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, TEST_URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        // Start timer
        clock_t start = clock();

        res = curl_easy_perform(curl);

        // Stop timer
        clock_t end = clock();
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);

        // Calculate speed
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long downloaded_bytes = chunk.size;
            double speed_mbps = (downloaded_bytes * 8) / (1024 * 1024 * time_taken); // Bits per second to MBps
            printf("Thank you for allowing me to measure your internet speed!\n");
            printf("Download speed: %.2f Mbps\n", speed_mbps);
            printf("Downloaded %ld bytes in %.2f seconds\n", downloaded_bytes, time_taken);
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
    }
    
    curl_global_cleanup();
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Let's find out how fast your internet connection is...\n\n");
    
    perform_speed_test();

    printf("\nThank you for using this application. Have a great day!\n");
    return 0;
}