//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL_TO_TEST "http://www.google.com"
#define BUFFER_SIZE 1024

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function for curl to write data to memory
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;  // Out of memory!
    }
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;  // Null-terminate
    return realsize;
}

// Function to perform an HTTP GET request and measure the time taken
double measure_speed() {
    CURL *curl_handle;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // initial allocation
    chunk.size = 0;            // no data at this point

    struct timeval start, end;
    gettimeofday(&start, NULL);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl_handle = curl_easy_init();
    
    if(curl_handle) {
        curl_easy_setopt(curl_handle, CURLOPT_URL, URL_TO_TEST);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1L);
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl_handle);

        // Check for errors
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup
        curl_easy_cleanup(curl_handle);
        free(chunk.memory);
    }

    gettimeofday(&end, NULL);
    curl_global_cleanup();
    
    // Calculate the time taken in seconds
    double time_taken = ((end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec)) / 1000000.0;
    return time_taken;
}

// Function to calculate speed from time taken
double calculate_speed(double time_taken) {
    double file_size = BUFFER_SIZE;  // Simulating a file size of 1MB for the test
    double speed = 0.0;

    if(time_taken > 0) {
        speed = (file_size / 1024 / 1024) / time_taken;  // Speed in MB/s
    }
    return speed;
}

// Main function
int main(void) {
    printf("=== Internet Speed Test ===\n");
    printf("Testing speed to: %s\n", URL_TO_TEST);

    double time_taken = measure_speed();
    double speed = calculate_speed(time_taken);

    printf("Time taken for the test: %.6f seconds\n", time_taken);
    printf("Estimated download speed: %.6f MB/s\n", speed);

    return 0;
}