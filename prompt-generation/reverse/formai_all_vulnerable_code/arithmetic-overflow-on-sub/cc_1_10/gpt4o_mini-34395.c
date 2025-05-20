//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

#define URL "http://speed.hetzner.de/100MB.bin"
#define BUFFER_SIZE 256

typedef struct {
    char *data;
    size_t size;
} MemoryStruct;

static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, MemoryStruct *userp) {
    size_t totalSize = size * nmemb;
    userp->data = realloc(userp->data, userp->size + totalSize + 1);
    if (userp->data == NULL) {
        printf("Not enough memory to allocate!\n");
        return 0; // Out of memory!
    }
    memcpy(&(userp->data[userp->size]), contents, totalSize);
    userp->size += totalSize;
    userp->data[userp->size] = 0;
    return totalSize;
}

void performSpeedTest() {
    CURL *curl;
    CURLcode res;

    MemoryStruct chunk;
    chunk.data = malloc(1);  // Initial allocation
    chunk.size = 0;          // No data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        // Set the URL for speed test
        curl_easy_setopt(curl, CURLOPT_URL, URL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC;
            double speed = (double)chunk.size / elapsedTime / (1024 * 1024); // Speed in MB/s
            printf("Download speed: %.2f MB/s\n", speed);
        }

        // Cleanup
        free(chunk.data);
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void displayMenu() {
    printf("==== Internet Speed Test ====\n");
    printf("1. Test Download Speed\n");
    printf("2. Exit\n");
    printf("=============================\n");
}

int main() {
    int choice;
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                performSpeedTest();
                break;
            case 2:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 2);
    
    return 0;
}