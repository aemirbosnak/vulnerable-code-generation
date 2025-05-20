//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *data;
    size_t size;
} MemoryBlock;

size_t WriteCallback(void *ptr, size_t size, size_t nmemb, MemoryBlock *mem) {
    size_t new_size = mem->size + size * nmemb;
    mem->data = realloc(mem->data, new_size + 1);
    if (mem->data == NULL) return 0;  // Out of memory

    memcpy(&(mem->data[mem->size]), ptr, size * nmemb);
    mem->size = new_size;
    mem->data[new_size] = '\0';  // Null-terminate the string

    return size * nmemb;
}

void print_speed(double bytes_downloaded, double seconds_taken) {
    double speed = (bytes_downloaded / (1024 * 1024)) / seconds_taken; // speed in MBps
    printf("Download Speed: %.2f MB/s\n", speed);
}

int main() {
    CURL *curl;
    CURLcode res;
    
    MemoryBlock chunk;
    chunk.data = malloc(1);  // Initial empty buffer
    chunk.size = 0;          // No data at this point

    // URL for test file (can be any sufficiently large file)
    const char *url = "http://speed.hetzner.de/10MB.bin";

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        clock_t start, end;
        start = clock();
        
        // Perform the request, res will get the return code
        res = curl_easy_perform(curl);
        end = clock();

        // Calculate total time taken
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        if(res == CURLE_OK) {
            printf("Successfully downloaded %zu bytes.\n", chunk.size);
            print_speed(chunk.size, time_taken);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Cleanup curl
        curl_easy_cleanup(curl);
        free(chunk.data);  // Free allocated memory
    } else {
        fprintf(stderr, "Could not initialize curl.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}