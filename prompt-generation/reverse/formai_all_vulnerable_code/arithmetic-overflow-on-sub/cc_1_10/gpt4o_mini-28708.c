//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

// A structure to hold the data we receive from a CURL request
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to handle the data received from CURL
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    
    if (userp->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0; // Out of memory!
    }
    
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate the string

    return realsize;
}

// Function to perform a speed test
void speed_test(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct data;

    data.memory = malloc(1);  // Initial allocation
    data.size = 0;            // No data at this point

    // Initialize CURL
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        struct timeval start, end;
        gettimeofday(&start, NULL); // Start time
        
        // Perform the request
        res = curl_easy_perform(curl);
        
        gettimeofday(&end, NULL);   // End time
        
        // Calculate the elapsed time
        long seconds = end.tv_sec - start.tv_sec;
        long micros = end.tv_usec - start.tv_usec;
        double elapsed = seconds + micros * 1e-6;

        // Handle response
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double speed = (double)data.size / (elapsed * 1024); // KB/s
            printf("Data received: %zu bytes\n", data.size);
            printf("Elapsed time: %.3f seconds\n", elapsed);
            printf("Speed: %.2f KB/s\n", speed);
        }
        
        // Clean up
        curl_easy_cleanup(curl);
        free(data.memory);
    } else {
        printf("Could not initialize CURL\n");
    }
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Internet Speed Test App!\n");
    printf("===========================\n");
    
    if (argc < 2) {
        printf("Usage: %s <URL to test>\n", argv[0]);
        return 1;
    }
    
    printf("Testing speed against: %s\n", argv[1]);
    speed_test(argv[1]);
    
    printf("===========================\n");
    printf("Thank you for using our Speed Test App! Goodbye!\n");
    
    return 0;
}