//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <sys/time.h>

#define URL "http://ipv4.download.thinkbroadband.com/10MB.zip"
#define DATA_SIZE (10 * 1024 * 1024) // 10MB
#define BUFFER_SIZE 4096

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

// Callback function writes data into memory
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    char *ptr = realloc(mem->memory, mem->size + realsize + 1);
    if (ptr == NULL) {
        fprintf(stderr, "Not enough memory for allocation\n");
        return 0; // Out of memory!
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0; // Null terminate

    return realsize;
}

// Function to initialize the CURL operation
long perform_speed_test(const char *url) {
    CURL *curl;
    CURLcode res;
    MemoryStruct chunk;

    chunk.memory = malloc(1);  // initial allocation
    chunk.size = 0;            // no data at this point

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L); // Ensure SSL is verified
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L); // Set timeout

        // Start time
        struct timeval start, end;
        gettimeofday(&start, NULL);

        res = curl_easy_perform(curl);

        // End time
        gettimeofday(&end, NULL);

        // Calculate duration
        double duration = (end.tv_sec - start.tv_sec) * 1e6; // Seconds to microseconds
        duration = (duration + (end.tv_usec - start.tv_usec)) * 1e-6; // Convert to seconds

        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            printf("Download completed in %.2f seconds\n", duration);
            printf("Downloaded data size: %lu bytes\n", chunk.size);
        }

        // Cleanup
        free(chunk.memory);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "Failed to initialize CURL\n");
        return -1;
    }

    return 0;
}

int main(void) {
    fprintf(stdout, "Internet Speed Test Application\n");
    fprintf(stdout, "Testing download speed...\n");
    long result = perform_speed_test(URL);
    
    if (result != 0) {
        fprintf(stderr, "Speed test failed with error code: %ld\n", result);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}