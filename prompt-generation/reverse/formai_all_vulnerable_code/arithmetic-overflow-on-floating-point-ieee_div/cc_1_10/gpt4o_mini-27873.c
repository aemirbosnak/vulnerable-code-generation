//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 100000 // Size of data to download
#define SERVER_URL "https://speed.hetzner.de/10MB.bin" // Test file URL

// Structure to hold the download data
struct Memory {
    char *response;
    size_t size;
};

// Callback function to write received data into Memory structure
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct Memory *mem) {
    size_t realsize = size * nmemb;
    mem->response = realloc(mem->response, mem->size + realsize + 1);
    if (mem->response == NULL) {
        printf("Not enough memory!\n");
        return 0; // Out of memory
    }
    memcpy(&(mem->response[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0; // Null terminate
    return realsize;
}

// Function to perform the speed test by downloading a file
double perform_speed_test() {
    CURL *curl;
    CURLcode res;
    struct Memory chunk;
    chunk.response = malloc(1); // Initial empty response
    chunk.size = 0; // Initial size

    curl_global_init(CURL_GLOBAL_DEFAULT); // Initialize global libcurl settings
    curl = curl_easy_init(); // Initialize a curl easy handle
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, SERVER_URL); // Set URL for curl
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback); // Set callback
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk); // Pass our struct
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); // Disable progress meter
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout
        clock_t start = clock(); // Start timing
        
        res = curl_easy_perform(curl); // Perform the curl request
        
        clock_t end = clock(); // End timing
        
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            return -1.0; // Return -1.0 if error occurs
        }
        
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate elapsed time
        double speed = (BUFFER_SIZE / (1024.0 * 1024.0)) / time_taken; // Calculate speed in MB/s
        
        // Clean up
        free(chunk.response);
        curl_easy_cleanup(curl);
        
        return speed; // Return the calculated speed
    }
    return -1.0; // Return -1.0 if curl initialization fails
}

// Main function to run the internet speed test application
int main(void) {
    printf("Welcome to the Curious Internet Speed Test Application!\n");
    printf(" We're about to measure how fast your internet connection is...\n\n");

    double speed = perform_speed_test(); // Call speed test function
    
    if (speed > 0) {
        printf("Your download speed is: %.2f MB/s\n", speed); // Display speed
    } else {
        printf("Failed to measure speed. Please check your network connection.\n");
    }

    printf("\nThank you for using the Curious Internet Speed Test! Come back anytime.\n");
    return 0;
}