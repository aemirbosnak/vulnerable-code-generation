//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://www.google.com" // Test URL for speed
#define BUFFER_SIZE 4096

// Structure to hold the data received from the HTTP request
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to handle the data received from curl
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }
    
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = '\0'; // Null-terminate the string
    return realsize;
}

// Function to initialize curl and perform the speed test
double perform_speed_test(CURL *curl, struct MemoryStruct *chunk) {
    curl_easy_setopt(curl, CURLOPT_URL, URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)chunk);
    curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

    // Start timing
    clock_t start_time = clock();

    // Perform the request
    CURLcode res = curl_easy_perform(curl);

    // Stop timing
    clock_t end_time = clock();
    
    // Check for errors
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return -1;
    }

    // Get the amount of data transferred
    double total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // Time in seconds
    long downloaded_size;
    curl_easy_getinfo(curl, CURLINFO_CONTENT_LENGTH_DOWNLOAD, &downloaded_size);
    
    // Calculate speed in Mbps
    double speed_mbps = (downloaded_size / 1024.0 / 1024.0) / total_time;
    return speed_mbps;
}

// Main function
int main(void) {
    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    
    if(curl) {
        struct MemoryStruct chunk;
        chunk.memory = malloc(1);  // Initial allocation
        chunk.size = 0;             // No data at start

        // Perform the speed test
        double speed = perform_speed_test(curl, &chunk);
        
        if (speed > 0) {
            printf("Download speed: %.2f Mbps\n", speed);
        }

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Curl initialization failed\n");
    }

    curl_global_cleanup();
    return 0;
}