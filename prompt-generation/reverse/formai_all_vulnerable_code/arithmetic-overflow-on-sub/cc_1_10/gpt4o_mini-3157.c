//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <time.h>

// Struct for writing data received from the server
struct MemoryStruct {
    char *memory;
    size_t size;
};

// Function to write data to our MemoryStruct
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, struct MemoryStruct *userp) {
    size_t realsize = size * nmemb;
    userp->memory = realloc(userp->memory, userp->size + realsize + 1);
    if (userp->memory == NULL) {
        printf("Not enough memory.\n");
        return 0;
    }
    memcpy(&(userp->memory[userp->size]), contents, realsize);
    userp->size += realsize;
    userp->memory[userp->size] = 0; // Null-terminate the string
    return realsize;
}

// Function to perform download speed test
double test_download_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);  // initial empty memory
    chunk.size = 0;             // no data at this point

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

        // Start time measurement
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();

        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            double speed = (chunk.size / 1024) / elapsed_time; // speed in KB/s
            printf("Download Speed: %.2f KB/s\n", speed);
        }

        curl_easy_cleanup(curl);
        free(chunk.memory);
    }

    curl_global_cleanup();
    return 0;
}

// Function to perform upload speed test
double test_upload_speed(const char *url) {
    CURL *curl;
    CURLcode res;
    const char *data = "This data will be uploaded.";
    struct curl_slist *headers = NULL;
    long http_code;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        headers = curl_slist_append(headers, "Content-Type: text/plain");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        // Start time measurement
        clock_t start = clock();
        res = curl_easy_perform(curl);
        clock_t end = clock();
        
        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
        
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
            double speed = (strlen(data) / 1024) / elapsed_time; // speed in KB/s
            printf("Upload Speed: %.2f KB/s, HTTP Response Code: %ld\n", speed, http_code);
        }

        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);
    }

    curl_global_cleanup();
    return 0;
}

int main(void) {
    const char *test_url = "http://www.example.com"; // Use a URL with sufficient bandwidth

    printf("Running Internet Speed Test...\n");
    test_download_speed(test_url);
    test_upload_speed(test_url);

    return 0;
}