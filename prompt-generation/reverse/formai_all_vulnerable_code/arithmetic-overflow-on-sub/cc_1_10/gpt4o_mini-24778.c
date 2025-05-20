//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

// Structure to hold the response data
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data to the allocated memory
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory!\n");
        return 0; // out of memory
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // null-terminate the string
    return realsize;
}

// Function to perform a speed test by downloading a file
double perform_speed_test(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // Initial allocation
    chunk.size = 0;            // No data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout
        
        // Start the clock for speed calculations
        clock_t start = clock();
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        // End the clock
        clock_t end = clock();
        
        // Calculate download time
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk.memory);
            curl_easy_cleanup(curl);
            curl_global_cleanup();
            return -1;
        }
        
        // Calculate speed in KB/s
        double speed = (chunk.size / 1024.0) / time_spent;
        printf("Downloaded %zu bytes in %.2f seconds at %.2f KB/s\n", chunk.size, time_spent, speed);

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    return 0;
}

int main() {
    char url[256] = "http://ipv4.download.thinkbroadband.com/10MB.zip"; // Changeable test file URL
    
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("This program measures download speed using a sample file.\n\n");

    // User input for URL
    printf("Enter a URL to test speed (or press Enter for default): ");
    fgets(url, sizeof(url), stdin);
    
    // Trim the newline character from the input
    url[strcspn(url, "\n")] = 0;
    
    if(strlen(url) == 0) {
        strcpy(url, "http://ipv4.download.thinkbroadband.com/10MB.zip");
    }
    
    printf("Testing speed for URL: %s\n", url);
    perform_speed_test(url);
    
    printf("Speed test complete! Thank you for using our application.\n");
    return 0;
}