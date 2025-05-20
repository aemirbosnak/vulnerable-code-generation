//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <curl/curl.h>

#define URL "https://www.google.com" // Test with a reliable website
#define BUFFER_SIZE 1024
#define TIMEOUT 10

struct MemoryStruct {
    char *memory;
    size_t size;
};

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *ptr) {
    size_t realsize = size * nmemb;
    ptr->memory = realloc(ptr->memory, ptr->size + realsize + 1);
    if (ptr->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(ptr->memory[ptr->size]), contents, realsize);
    ptr->size += realsize;
    ptr->memory[ptr->size] = '\0'; // Null terminate
    return realsize;
}

void perform_speed_test() {
    struct timeval start, end;
    double elapsed;
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, TIMEOUT);

        gettimeofday(&start, NULL); // Start timing
        res = curl_easy_perform(curl);
        gettimeofday(&end, NULL); // Stop timing

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            long response_code;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &response_code);
            printf("Response Code: %ld\n", response_code);
        }

        elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0; // Elapsed time in milliseconds
        printf("Time taken for test: %.2f milliseconds\n", elapsed);
        if (chunk.size > 0) {
            printf("Downloaded %zu bytes of data\n", chunk.size);
        } else {
            printf("No data downloaded.\n");
        }
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
    free(chunk.memory);
}

int main() {
    printf("***** Welcome to the Internet Speed Test *****\n");
    printf("Testing download speed by fetching data from %s...\n", URL);
    
    perform_speed_test();

    printf("Test completed! Check your connection and try again if necessary.\n");
    return 0;
}