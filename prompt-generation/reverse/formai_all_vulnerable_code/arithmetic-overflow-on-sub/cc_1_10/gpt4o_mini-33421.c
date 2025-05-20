//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <curl/curl.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *memory;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, MemoryStruct *data) {
    size_t realsize = size * nmemb;
    data->memory = realloc(data->memory, data->size + realsize + 1);
    if (data->memory == NULL) {
        printf("Not enough memory!\n");
        return 0;
    }
    memcpy(&(data->memory[data->size]), ptr, realsize);
    data->size += realsize;
    data->memory[data->size] = 0;
    return realsize;
}

void performSpeedTest(const char *url) {
    CURL *curl;
    CURLcode res;
    MemoryStruct data;
    data.memory = malloc(1);
    data.size = 0;
    long speed;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        
        // Start the timer
        clock_t start = clock();

        // Perform the request
        res = curl_easy_perform(curl);
        
        // End the timer
        clock_t end = clock();
        
        if(res == CURLE_OK) {
            double elapsed_time = ((double)(end - start)) / CLOCKS_PER_SEC; // Calculate elapsed time
            curl_easy_getinfo(curl, CURLINFO_SPEED_DOWNLOAD, &speed);
            printf("Downloaded %lu bytes in %.2f seconds.\n", data.size, elapsed_time);
            printf("Avg Download Speed: %.2f bytes/sec\n", (double)data.size / elapsed_time);
            printf("Current Download Speed: %ld bytes/sec\n", speed);
        } else {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // Clean up
        curl_easy_cleanup(curl);
        free(data.memory);
    } else {
        fprintf(stderr, "Failed to initialize CURL.\n");
    }
    
    curl_global_cleanup();
}

void displayMenu() {
    printf("=== Internet Speed Test ===\n");
    printf("1. Test Download Speed\n");
    printf("2. Test Upload Speed\n");
    printf("3. Exit\n");
    printf("==========================\n");
    printf("Select an option: ");
}

int main() {
    int option;
    char downloadUrl[] = "http://ipv4.download.thinkbroadband.com/5MB.zip";
    
    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Testing Download Speed...\n");
                performSpeedTest(downloadUrl);
                break;
            case 2:
                // Placeholder for upload speed test
                printf("Upload Speed test feature is under development.\n");
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}