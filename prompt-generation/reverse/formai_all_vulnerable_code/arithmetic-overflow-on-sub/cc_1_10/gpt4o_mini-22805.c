//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curl/curl.h>
#include <time.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

void init_memory(MemoryStruct *mem) {
    mem->memory = malloc(1);
    mem->memory[0] = '\0';
    mem->size = 0;
}

size_t write_callback(void *ptr, size_t size, size_t nmemb, MemoryStruct *mem) {
    size_t realsize = size * nmemb;
    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(mem->memory[mem->size]), ptr, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';
    return realsize;
}

double measure_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;

    MemoryStruct chunk;
    init_memory(&chunk);
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        clock_t start_time = clock();
        res = curl_easy_perform(curl);
        clock_t end_time = clock();

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            free(chunk.memory);
            return -1.0;
        }
        
        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC; // seconds
        double bytes_downloaded = chunk.size;
        
        double speed = (bytes_downloaded / 1024) / elapsed_time; // KB/s
        free(chunk.memory);
        curl_easy_cleanup(curl);
        return speed;
    } else {
        fprintf(stderr, "Failed to initialize curl!\n");
        free(chunk.memory);
        return -1.0;
    }
}

void measure_upload_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    char data[BUFFER_SIZE];

    // Fill data with random contents
    for (int i = 0; i < BUFFER_SIZE; i++) {
        data[i] = 'a' + (rand() % 26);
    }

    clock_t start_time = clock();
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        res = curl_easy_perform(curl); // Sending the data

        clock_t end_time = clock();
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
        double bytes_uploaded = BUFFER_SIZE;

        double speed = (bytes_uploaded / 1024) / elapsed_time; // KB/s
        printf("Upload Speed: %.2f KB/s\n", speed);
        
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

int main(void) {
    const char *download_url = "https://example.com/some-large-file"; // placeholder
    const char *upload_url = "https://example.com/upload"; // placeholder
    
    printf("**** 🎉 Internet Speed Test Application 🎉 ****\n");
    printf("Calculating download speed...\n");

    double download_speed = measure_download_speed(download_url);
    if (download_speed > 0) {
        printf("Download Speed: %.2f KB/s\n", download_speed);
    } else {
        printf("Could not calculate download speed.\n");
    }

    printf("Calculating upload speed...\n");
    measure_upload_speed(upload_url);
    
    printf("**** End of Speed Test ****\n");
    return 0;
}