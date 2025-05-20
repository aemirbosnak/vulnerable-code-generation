//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <time.h>

struct MemoryStruct {
    char *memory;
    size_t size;
};

// Callback function to write data from CURL to our MemoryStruct
size_t WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, struct MemoryStruct *data) {
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

// Function to test internet speed
void testSpeed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct data;

    data.memory = malloc(1);  // initial allocation
    data.size = 0;            // no data at this point

    curl = curl_easy_init();
    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&data);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        time_t start, end;
        start = time(NULL);

        res = curl_easy_perform(curl);
        
        end = time(NULL);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double total_time = difftime(end, start);
            printf("Download completed!\n");
            printf("Downloaded %zu bytes in %.2f seconds.\n", data.size, total_time);
            double speed_mbps = (data.size * 8) / (total_time * 1000000); // Convert to Mbps
            printf("Speed: %.2f Mbps\n", speed_mbps);
        }

        curl_easy_cleanup(curl);
        free(data.memory);
    } else {
        fprintf(stderr, "Curl initialization failed!\n");
    }
}

int main() {
    char url[256];

    printf("Welcome to the Internet Speed Test Application!\n");
    printf("Please enter a URL to test the download speed (e.g., http://example.com): ");
    fgets(url, sizeof(url), stdin);
    url[strcspn(url, "\n")] = 0; // Remove newline character

    if(strlen(url) > 0) {
        printf("Testing download speed for: %s\n", url);
        testSpeed(url);
    } else {
        printf("Invalid URL! Please enter a proper URL next time.\n");
    }

    return 0;
}