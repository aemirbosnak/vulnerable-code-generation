//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://ipv4.download.thinkbroadband.com/10MB.zip" // Sample file for testing
#define FILE_SIZE_MB 10 // Size of the file in MB for testing
#define BUFFER_SIZE 2048 // Download buffer size
#define NUMBER_OF_TESTS 3 // Number of speed tests to run

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function that writes the downloaded data to our memory structure
size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *mem) {
    size_t realsize = size * nmemb;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory for download!\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // Null terminator

    return realsize;
}

double test_speed() {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;

    chunk.memory = malloc(1); // initial memory allocation
    chunk.size = 0; // no data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Start timing the download
        clock_t start = clock();
        
        // Perform the download
        res = curl_easy_perform(curl);
        
        // End timing the download
        clock_t end = clock();
        double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double download_speed = (FILE_SIZE_MB * 1024 * 1024) / time_spent; // bytes per second
            printf("Download speed: %.2f MB/s\n", download_speed / (1024 * 1024)); // Convert to MB/s
        }

        // Cleanup
        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();

    return 0;
}

int main() {
    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Testing your download speed...\n");

    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        printf("Test %d:\n", i + 1);
        test_speed();
        printf("------------------------------\n");
    }

    printf("Tests completed. Thank you for using the Speed Test Application!\n");
    return 0;
}